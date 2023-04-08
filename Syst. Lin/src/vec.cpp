#include "vec.hpp"

std::vector<double> diff(const std::vector<double>& v,const  std::vector<double>& w){
  std::vector<double> z;
  if (v.size() != w.size()){
    std::cerr << "Attention pb de dimension diff vec" << std::endl;
    std::exit(1);
  }
  for(unsigned int i=0; i<v.size();i++) z.push_back(v[i]-w[i]);
  return z;
}

std::vector<double> sum(const std::vector<double>& v,const std::vector<double>& w){
  std::vector<double> z;
  if (v.size() != w.size()){
    std::cerr << "Attention pb de dimension somme vec" << std::endl;
    std::exit(1);
  }  for(unsigned int i=0; i<v.size();i++) z.push_back(v[i]+w[i]);
   return z;
}

std::vector<double> prod(const std::vector<double> &v, const double& a){
  std::vector<double> z(v.size());
  for(unsigned int i=0; i<v.size();i++) z[i]=v[i]*a;
  return z;
}

std::vector<double> div(const std::vector<double> &v, const double& a){
  if(std::abs(a)<1e-5){
    std::cerr << "Attention div par 0 dans prod vect/scalaire" << std::endl;
    std::exit(1);
  }
  std::vector<double> z(v.size());
  for(unsigned int i=0; i<v.size();i++) z[i]=v[i]/a;
  return z;
}

double norm2(const std::vector<double>& v){
  double x=0.;
  for (unsigned int i=0;i<v.size();i++) x+=v[i]*v[i];
  return sqrt(x);
}

double scal(const std::vector<double>& v,const std::vector<double>& w){
  if (v.size() != w.size() ) std::cout<<"Pb de taille dans le produit scalaire des vecteurs";
  double x=0.;
  for(unsigned int i=0; i<v.size();i++) x+=v[i]*w[i];
   return x;
}

void print(const std::vector<double>& v){
  int n=v.size();
  std::cout<<"Taille: "<<n<<std::endl;
  for(int i=0;i<n;i++){
    std::cout<<v[i]<<" ";
  }
  std::cout<<std::endl<<std::endl;
}
   
std::pair<double,double> MeanVar_res(const std::vector<double>& vres){
  double mean=0;
  double var=0;
  unsigned int n =vres.size(); 
  for(unsigned int i=0;i<n;i++){
    mean += vres[i];
    var  += vres[i]*vres[i];
  }
  mean/=n; var/=n;
  var-= mean*mean;
  return std::make_pair(mean,var);
}
