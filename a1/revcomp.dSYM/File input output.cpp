#include<iostream>
#include<string>
#include<>
ifstream infile(filename);
if(! infile fail()){
  string line;
  while(get line(infile.line)){
      //do something with the line .
  }
  infile.close();
}else{
  cerr<<"could not open file"<<filename<<endl;
  exit(EXIT_FALIURE)
}
