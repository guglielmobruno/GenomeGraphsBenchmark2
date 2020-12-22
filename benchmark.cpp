#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>
#include <mach/mach.h>
#include <mach/vm_statistics.h>
#include <mach/mach_types.h>
#include <mach/mach_init.h>
#include <mach/mach_host.h>
using namespace std;
int main(int argc, char *argv[]){
  string nomefile = argv[1];
  string intera="\0",trash, ciao="ciao";
  char c;
  int i,j=0,h=0,x,cont=0;
  int grad=3,k=101;
  ifstream countFile(nomefile);
  while(countFile.get(c)){
    if(c=='>') getline(countFile,trash);
    else{
      if(c!='\n'&&c!=' '&&c!='\t') intera=intera+c;
    }
  }
  cout<<intera.size();
  ofstream wholeFile(nomefile+"_whole_sequence"+".gfa");
  wholeFile<<"S"<<'\t'<<'1'<<'\t'<<intera;
  wholeFile.close();
  ofstream singleFile(nomefile+"_single_character"+".gfa");
  for(i=0;i<intera.size();i++){
    singleFile<<"S"<<'\t'<<i+1<<'\t'<<intera[i]<<'\n';
  }
  for(i=0;i<intera.size()-1;i++){
    singleFile<<"L"<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
  }
  singleFile.close();
  ofstream kFile(nomefile+"_kmer"+".gfa");
  while(j<intera.size()){
    kFile<<'S'<<'\t'<<h+1<<'\t';
    for(i=0;i<k;i++){
      if(j+i<intera.size()) kFile<<intera[j+i];
    }
    kFile<<'\n';
    j+=k;
    h++;
  }
  for(i=0;i<h-1;i++){
    kFile<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
  }
  kFile.close();
  ofstream fitt3File(nomefile+"_fittizi_grad3"+".gfa");
  j=0;
  h=0;
  while(j<intera.size()){
    fitt3File<<'S'<<'\t'<<h+1<<'\t';
    for(i=0;i<k;i++){
      if(j+i<intera.size()) fitt3File<<intera[j+i];
    }
    fitt3File<<'\n';
    j+=k;
    h++;
  }
  for(i=0;i<h-1;i++){
    fitt3File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+20<h) fitt3File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+20<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+10<h) fitt3File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+10<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+40<h) fitt3File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+40<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+5<h) fitt3File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+5<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
  }
  fitt3File.close();
  ofstream fitt2File(nomefile+"_fittizi_grad2"+".gfa");
  j=0;
  h=0;
  while(j<intera.size()){
    fitt2File<<'S'<<'\t'<<h+1<<'\t';
    for(i=0;i<k;i++){
      if(j+i<intera.size()) fitt2File<<intera[j+i];
    }
    fitt2File<<'\n';
    j+=k;
    h++;
  }
  for(i=0;i<h-1;i++){
    fitt2File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+20<h) fitt2File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+20<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+10<h) fitt2File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+10<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
  }
  fitt2File.close();
  ofstream fitt5File(nomefile+"_fittizi_grad5"+".gfa");
  j=0;
  h=0;
  while(j<intera.size()){
    fitt5File<<'S'<<'\t'<<h+1<<'\t';
    for(i=0;i<k;i++){
      if(j+i<intera.size()) fitt5File<<intera[j+i];
    }
    fitt5File<<'\n';
    j+=k;
    h++;
  }
  for(i=0;i<h-1;i++){
    fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+20<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+20<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+10<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+10<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+40<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+40<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+6<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+6<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+30<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+30<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+8<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+8<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+60<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+60<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+5<h) fitt5File<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+5<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
  }
  ofstream cyclicFile(nomefile+"_ciclico"+".gfa");
  j=0;
  h=0;
  while(j<intera.size()){
    cyclicFile<<'S'<<'\t'<<h+1<<'\t';
    for(i=0;i<k;i++){
      if(j+i<intera.size()) cyclicFile<<intera[j+i];
    }
    cyclicFile<<'\n';
    j+=k;
    h++;
  }
  for(i=0;i<h-1;i++){
    cyclicFile<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+2<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(i+20<h) cyclicFile<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+20<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    else if(i+10<h) cyclicFile<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i+10<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    if(cont%17==0) cyclicFile<<'L'<<'\t'<<i+1<<'\t'<<'+'<<'\t'<<i-15<<'\t'<<'+'<<'\t'<<"0M"<<'\n';
    cont++;
  }
  cyclicFile.close();
  return 0;
}
