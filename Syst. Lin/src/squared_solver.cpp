#include "mat.hpp"

//DIRECT_SOLVER_________________________________________________________________
void decomp_LU(Mat &A,std::vector<double>& b){
  for (int k =0;k<A.row();k++){
// Pivot
    double pivot = A(k,k);
    int ip=k;
     if (abs(pivot) < 1e-14){
       for(int i= k+1;i<A.row();i++){
     	if (A(i,k) > A(ip,k)) ip=i;   
       }
       A.permute(k,ip);
       iter_swap(b.begin()+k,b.begin()+ip);
     }
     
// Colonne de L
    for (int i = k+1; i<A.row();i++){
	A(i,k) = A(i,k)/pivot;
      }
// ComplÃ©ment de Schur
    for (int i = k+1;i<A.row();i++){
      for (int j = k+1; j<A.row();j++){
	A(i,j) -= A(i,k)*A(k,j);
      }
    }
  }
}

std::vector<double> solve_triang_sup(const Mat &A, const std::vector<double>& b){
  int n =b.size();
  std::vector<double> x(n);
  x[n-1]= b[n-1]/A(n-1,n-1);
  for (int i=n-2; i>=0;i--){
    double t=0.;
    for (int j=n-1; j>i; j--){
      t = t + A(i,j)*x[j];
    }
    x[i]= b[i]/A(i,i)-t/A(i,i);
  }
  return(x);
}

std::vector<double> solve_triang_inf_id(const Mat &A, const std::vector<double>& b){
  int n =b.size();
  std::vector<double> x(n);
  x[0]= b[0];
  for (int i=1; i<n; i++){
    double t = 0.;
    for (int j=0; j<i; j++){
      t = t+ A(i,j)*x[j];
    }
    x[i] = b[i]-t;
  }
  return(x);
}

void Solve(const Mat &A, std::vector<double> &x, const std::vector<double> &b){
  if(A.row()!=A.col()){
    std::cerr << "Attention Matrice pas carrée" << std::endl;
    std::exit(1);
  }
  std::vector<double> bp(b);
  Mat LU(A);
  decomp_LU(LU,bp);
  x=solve_triang_sup(LU,solve_triang_inf_id(LU,bp));
}

//RESIDU________________________________________________________________________
double res(const Mat& A,const std::vector<double>& x,const std::vector<double>& b){
  std::vector<double> b_;
  MvProd(A,x,b_);
  return pow(norm2(diff(b_,b)),2);
}

