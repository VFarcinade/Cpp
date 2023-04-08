#include "mat.hpp"
#include "vec.hpp"
#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <tuple>
#include <chrono>


int main (){
  
  // //TEST SOLVEUR CLASSIQUE_______________________________________________
  Mat A(5,5);
  A.Laplace();
  //A(1,1)=0;
  std::cout<<A<<std::endl;
  std::vector<double> b(5,1.);
  std::vector<double> b_;
  std::vector<double> x;
  Solve(A,x,b);
  MvProd(A,x,b_);
  std::cout<<"Resultat de A*x-b: "<<std::endl;
  print(b_);


  // // TESTS SOLVEURS MC__________________________________________________
  //Si l'on veut tester notre fact QR, il suffit de décommenter les lignes correspondantes dans le code des solveurs
  //Si l'on veut récupérer les matrices Q et R, on pourrait par exemple ajouter une pair<Mat,Mat> en référence en
  //argument des solveurs et y stocker les deux matrices

  
  // //PB ADMETTANT UNE SOL EXACT___________________
  // std::mt19937 G(time(nullptr));
  // Mat A(8,3,G);
  // std::vector<double> sol(3,1.);
  // std::vector<double> b;
  // MvProd(A,sol,b);
  // std::vector<double> x1;
  // std::vector<double> x2;
  // std::vector<double> x3;
  // NormalSolve(A,x1,b);
  // GramSchmidtSolve(A,x2,b);
  // HouseholderSolve(A,x3,b);
  
  // std::cout<<"Solveur par Eqnorm: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x1,b)<<std::endl<<std::endl;
  // std::cout<<"Solveur par GS: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x2,b)<<std::endl<<std::endl;
  // std::cout<<"Solveur par HH: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x3,b)<<std::endl<<std::endl;
  
  
  
  
  
  // //PB ALEATOIRE___________________________________
  // std::mt19937 G(time(nullptr));
  // Mat A(8,3,G);
  // std::vector<double> b(8,1.);
  // std::vector<double> x1;
  // std::vector<double> x2;
  // std::vector<double> x3;
  // NormalSolve(A,x1,b);
  // GramSchmidtSolve(A,x2,b);
  // HouseholderSolve(A,x3,b);

  // std::cout<<"Solveur par Eqnorm: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x1,b)<<std::endl<<std::endl;
  // std::cout<<"Solveur par GS: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x2,b)<<std::endl<<std::endl;
  // std::cout<<"Solveur par HH: "<<std::endl;
  // std::cout<<"Residu= "<<res(A,x3,b)<<std::endl<<std::endl;


  
  //OBS DE LA METHODE LA PLUS RAPIDE
  // clock_t start, end;
  // int n=800,m=30;
  // std::mt19937 G(time(nullptr));
  // int nb_test=5;
  // std::vector<double> b(n,1.);
  // std::vector<double> x1;
  // std::vector<double> x2;
  // std::vector<double> x3;
  // std::vector<double> cpu1(nb_test);
  // std::vector<double> cpu2(nb_test);
  // std::vector<double> cpu3(nb_test);
  // for(int i=0;i<nb_test;i++){
  //   Mat A(n,m,G);
  //   start = clock();
  //   NormalSolve(A,x1,b);
  //   end = clock();
  //   cpu1[i] = static_cast<double>(end - start) / CLOCKS_PER_SEC ;
  //   start = clock();
  //   GramSchmidtSolve(A,x2,b);
  //   end = clock();
  //   cpu2[i] = static_cast<double>(end - start) / CLOCKS_PER_SEC ;
  //   start = clock();
  //   HouseholderSolve(A,x3,b);
  //   end = clock();
  //   cpu3[i] = static_cast<double>(end - start) / CLOCKS_PER_SEC ;
  // }

  //  std::pair<double,double> p1=MeanVar_res(cpu1);
  //  std::pair<double,double> p2=MeanVar_res(cpu2);
  //  std::pair<double,double> p3=MeanVar_res(cpu3);
  //  std::cout<<"Moyenne du temps de resolution avc solveur Eqnorm: "<<p1.first<<" et variance: "<<p1.second<<std::endl;
  //  std::cout<<"Moyenne du temps de resolution avc solveur GrammS: "<<p2.first<<" et variance: "<<p2.second<<std::endl;
  //  std::cout<<"Moyenne du temps de resolution avc solveur HouseH: "<<p3.first<<" et variance: "<<p3.second<<std::endl;



   //OBS DE LA CROISSANCE DU RES EN FONCTION DE N et M
  // std::mt19937 G(time(nullptr));
  // int nb_test=100;
  // std::vector<double> x1;
  // std::vector<double> res1;
  // for(int n=10;n<=150;n=n+10){
  //   int m=5;
  //   std::vector<double> moy_res_n;
  //   for(int i=0;i<nb_test;i++){
  //     Mat A(n,m,G);
  //     std::vector<double> b(n,1.);
  //     NormalSolve(A,x1,b);
  //     moy_res_n.push_back(res(A,x1,b));
  //   }
  //   res1.push_back(MeanVar_res(moy_res_n).first);
  // }
  // std::cout<<"RESIDU MOYEN POUR M FIXE A 5 ET N DE 10 A 150 PAR PAS DE 10"<<std::endl<<std::endl;
  // print(res1);
  // std::cout<<std::endl;
  
  // std::vector<double> res2;
  // for(int m=36;m<=50;m++){
  //   int n=50;
  //   std::vector<double> moy_res_m;
  //   for(int i=0;i<nb_test;i++){
  //     Mat A(n,m,G);
  //     std::vector<double> b(n,1.);
  //     NormalSolve(A,x1,b);
  //     moy_res_m.push_back(res(A,x1,b));
  //   }
  //   res2.push_back(MeanVar_res(moy_res_m).first);
  // }
  // std::cout<<"RESIDU MOYEN POUR N FIXE A 50 ET M DE 35 A 50 PAR PAS DE 1"<<std::endl<<std::endl;
  // print(res2);
  
   
  return 0;
}
