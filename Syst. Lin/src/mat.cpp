#include "mat.hpp"

Mat::Mat(const int& nr,const int& nc,std::mt19937 &G):NbRow(nr),NbCol(nc),coef(nr*nc,0.){
  std::normal_distribution<double> N(0,1);
  for(int i=0;i<nr*nc;i++) coef[i]=N(G);
}

Mat& Mat::operator=(const Mat& M){
  if( NbRow==M.row() && NbCol==M.col() && coef==M.coef) return (*this);
  NbRow=M.row();
  NbCol=M.col();
  coef=M.coef;
  return((*this));
}

std::ostream& operator<<(std::ostream& os, const Mat& m){
  os <<"#TAILLE"<<std::endl<<m.row()<<" "<<m.col()<<std::endl<<"#DONNEES"<<std::endl;
  for(int i=0; i<m.row();i++){
    for(int j=0;j<m.col();j++){
      os << m(i,j)<<" ";
      if (j+1==m.col()) os <<std::endl;
  }
  }
  return os;
}

bool operator==(const Mat& A, const Mat& B){
  if(A.row() != B.row()) return 0;
  else if(A.col() != B.col()) return 0;
  for(int i=0;i<A.row();i++){
    for(int j=0;j<A.col();j++){
      if (abs(A(i,j)-B(i,j))> pow(10,-4))return 0;
    }
  }
  return 1;
}

void Mat::Load(char* const filename){
  std::ifstream F(filename);
  std::string s;
  F >> s >> NbRow >> NbCol>>s;
  double x;
  int i=0;
  coef.resize(NbRow*NbCol);
  while(F>>x){
    coef[i]=x;
    i++;
  }
  F.close();
}

void Mat::Laplace(){
  int n=row();
  if (n!=col()){
    col()=n;
    std::cout<<"redim de la matrice pour créer une laplacienne"<<std::endl;
  }		  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j-i==1 || j-i ==-1) (*this)(i,j) = -1;
      else if (i==j) (*this)(i,j) =2;
      else (*this)(i,j)=0;
    }
  }
}

void Mat::Identity(){
  int n=row();
  if (n!=col()){
    col()=n;
    std::cout<<"redim de la matrice pour créer une mat. identité"<<std::endl;
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if (i==j) (*this)(i,j) =1;
      else (*this)(i,j)=0;
    }
  }
}

void Mat::permute(const int& i,const int& j){
  double x;
  for(int k=0;k<row();k++){
    x=(*this)(i,k);
    (*this)(i,k)=(*this)(j,k);
    (*this)(j,k)=x;
  }
}


void trans(const Mat& A,Mat& tA){
  tA.resize(A.col(),A.row());
  for(int i=0;i<tA.row();i++){
    for(int j=0;j<tA.col();j++){
      tA(i,j)=A(j,i);
    }
  }
}

std::vector<double> extract_col(const Mat& M,const int& j){
  std::vector<double> v(M.row());
  for(int i=0;i<M.row();i++) v[i]=M(i,j);
  return v;
}
