#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <random>

#include "vec.hpp"


class Mat {
private:
  int NbRow;
  int NbCol;
  std::vector<double> coef;

public:
  
  //Constructeurs_______________________________________________________
  Mat(const int& nr=0,const int& nc=0):NbRow(nr),NbCol(nc),coef(nr*nc,0.){};
  Mat(const Mat& M):NbRow(M.NbRow),NbCol(M.NbCol),coef(M.coef){};
  Mat(const int& nr,const int& nc,std::mt19937 &G);
  //____________________________________________________________________


  //Operateurs classiques_______________________________________________
  Mat& operator=(const Mat& M);
  friend std::ostream& operator<<(std::ostream& os, const Mat& m);
  friend bool operator==(const Mat& A, const Mat& B);
  //____________________________________________________________________

  
  //Fonctions propres à la classe_______________________________________
  void Load(char* const filename);
  void Laplace();
  void Identity();
  void resize(const int& i,const int& j){ row()=i; col()=j; coef.resize(i*j);}
  int nb_elem() const { return coef.size();}
  void permute(const int& i, const int& j);
  friend void trans(const Mat& A,Mat& tA);
  friend std::vector<double> extract_col(const Mat& M,const int& j);
  //____________________________________________________________________


  

  //Accesseurs et mutateurs aux différents éléments_____________________
  int row() const { return NbRow;}
  int col() const { return NbCol;}
  int& row(){ return NbRow;}
  int& col(){ return NbCol;}
  double& operator()(const int& i, const int& j){return coef[col()*i+j];}
  double operator()(const int& i, const int& j)const{return coef[col()*i+j];}
  //____________________________________________________________________



  
  //Operations___________________________________________________________
  friend void MvProd(const Mat& A,const std::vector<double>& x,std::vector<double>& b);
  friend void vMProd(const std::vector<double>& x,const Mat& A,std::vector<double>& b);
  friend void MMProd(const Mat& A,const Mat& B,  Mat& C);
  
  friend Mat HhProd(const Mat& A, const std::vector<double>& v);
  friend Mat HhProd(const std::vector<double>& v, const Mat& A);
  //_____________________________________________________________________

  
  
  //Solveurs_____________________________________________________________
  //Solveurs classiques
  friend void decomp_LU(Mat &M,std::vector<double>& b);
  friend std::vector<double> solve_triang_sup(const Mat &A, const std::vector<double>& b);
  friend std::vector<double> solve_triang_inf_id(const Mat &A, const std::vector<double>& b);
  friend void Solve(const Mat& A,std::vector<double>& x,const std::vector<double>& b);

  //Calcul du residu
  friend double res(const Mat& A,const std::vector<double>& x,const std::vector<double>& b);

  //Solveur equation normal
  friend void NormalSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b);

  //Solveur GramShmidt
  friend void GramSchmidtSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b);

  //solveur HouseHolder
  friend void HouseholderSolve(const Mat& A,std::vector<double>& x,const std::vector<double>& b);

  //_____________________________________________________________________
  
};
