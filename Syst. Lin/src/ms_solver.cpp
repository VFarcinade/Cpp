#include "mat.hpp"



void NormalSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b){
  int n=b.size();
  if(A.row()!=n){
    std::cerr << "Attention pb de dimension entre Matrice et Vecteur" << std::endl;
    std::exit(1);
  }
  Mat tA,A_;
  trans(A,tA);
  std::vector<double> b_(A.row());
  MMProd(tA,A,A_);
  MvProd(tA,b,b_);
  Solve(A_,x,b_);
}




//_________________________________________________________________________________________





void GramSchmidtSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b){

  //verif
  int n=A.row();
  int m=A.col();
  int nb=b.size();
  if(n != nb){
    std::cerr << "Attention pb de dimension entre Matrice et Vecteur" << std::endl;
     std::exit(1);
  }
  
  //ititialisation
  Mat Q(n,m),R(m,m),tQ;

   auto modify_col=[&](const int& j,const std::vector<double> &v){	
		    for(int i=0;i<Q.row();i++) Q(i,j)=v[i];
		   };
   
   std::vector<double> w=extract_col(A,0);
  modify_col(0,div(w,norm2(w)));
  R(0,0)=norm2(w);

  
  //remplissage Q & R
  for(int k=1;k<m;k++){
    w=extract_col(A,k);
    for(int j=0;j<k;j++){
      std::vector<double> q_j(extract_col(Q,j));
      R(j,k)=scal(q_j,w);
      w=diff(w,prod(q_j,R(j,k)));
    }
    R(k,k)=norm2(w);
    modify_col(k,div(w,R(k,k)));
  }
  //std::cout<<"GramSchmidt Q: "<<std::endl<<Q<<std::endl;
  //std::cout<<"GramSchmidt R: "<<std::endl<<R<<std::endl;
  //Mat test(n,m);
  //MMProd(Q,R,test);
  //if (test==A) std::cout<<"Decomp QR GrammSchmidt OK"<<std::endl;
  //else std::cout<<"Decomp QR GrammSchmidt pas OK"<<std::endl;
  
  //resoultion syst.
  trans(Q,tQ);
  std::vector<double> tQb(m);
  MvProd(tQ,b,tQb);
  x=solve_triang_sup(R,tQb);  
}




//_________________________________________________________________________________________






void HouseholderSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b){

  //verif
  int n=A.row(),m=A.col(),nb=b.size();
  if(n != nb ){
    std::cerr << "Attention pb de dimension entre Matrice et Vecteur" << std::endl;
    std::exit(1);
  }

  
  //initialisation
  Mat Q(n,m),R(n,m),tQ;
  Mat Q_(n,n);
  std::vector<double> u0(extract_col(A,0));
  u0[0]-=norm2(u0);
  Q_.Identity();
  R=HhProd(u0,A);
  Q_=HhProd(Q_,u0);

  
  //Construction de Q' & Rm
  for(int p=1;p<m;p++){
    std::vector<double> up(n);
    for(int j=p;j<n;j++) up[j]=R(j,p);
    up[p]-=norm2(up);
    R=HhProd(up,R);
    Q_=HhProd(Q_,up);
  }
 
  //Construction de Q et R
  R.resize(m,m);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      Q(i,j)=Q_(i,j);
    }
  }
  //std::cout<<"HouseHolder Q: "<<std::endl<<Q<<std::endl;
  //std::cout<<"HouseHolder R: "<<std::endl<<R<<std::endl;
  //Mat test(n,m);
  //MMProd(Q,R,test);
  //if (test==A) std::cout<<"Decomp QR HouseHolder OK"<<std::endl;
  //else std::cout<<"Decomp QR HouseHolder pas OK"<<std::endl;
    
  //resoultion syst.
  trans(Q,tQ);
  std::vector<double> tQb(m);
  MvProd(tQ,b,tQb);
  x=solve_triang_sup(R,tQb);  
}
