#include "mat.hpp"

void MvProd(const Mat& A,const std::vector<double>& x,std::vector<double>& b){
  int m = x.size();
  if(A.col() != m) {
     std::cerr <<"PB de dimension !"<< std::endl;
     std::exit(1);
  }else{
    int n=A.row();
    b.resize(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	b[i]+=A(i,j)*x[j];
      }
    }
  }
}

void vMProd(const std::vector<double>& x,const Mat& A,std::vector<double>& b){
  int n = x.size();
  if(A.row() != n) {
     std::cerr <<"PB de dimension ! "<< std::endl;
     std::exit(1);
  }else{
    int m=A.col();
    b.resize(m);
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
	b[i]+=A(j,i)*x[j];
      }
    }
  }
}


void MMProd(const Mat& A,const Mat& B, Mat& C){
  int n1 = A.row();
  int m1 = A.col();
  int n2 = B.row();
  int m2 = B.col();
   if(n2 != m1) {
     std::cerr <<"PB de dimension !"<< std::endl;
     std::exit(1);
  }else{
     C.resize(n1,m2);
     for(int i=0;i<n1;i++){
       for(int j=0;j<m2;j++){
	 for(int k=0;k<n2;k++){
	   C(i,j)+=A(i,k)*B(k,j);
	 }
       }
     }
   }
}

Mat HhProd(const Mat& A, const std::vector<double>& v){
  int n=A.row();
  Mat B(n,n);
  double x=2./scal(v,v);
  
  std::vector<double> w;
  MvProd(A,v,w);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      B(i,j)=A(i,j)-w[i]*v[j]*x;
    }
  }
  
  return B;
}


Mat HhProd(const std::vector<double>& v, const Mat& A){
  int n=A.row(),m=A.col();
  Mat B(n,m);
  double x=2./scal(v,v);
  
  std::vector<double> w;
  vMProd(v,A,w);
  
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      B(i,j)=A(i,j)-v[i]*w[j]*x;
    }
  }
  
  return B;
}
