
#include "dna.h"
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include<fstream>
//constructor.
DNA::DNA(){
  hdr=">";
  seq="";
}
DNA::DNA(std::string header, std::string sequence){
    if(header[0] != '>'){
      throw std::runtime_error("informative error message");
    }
        //loop to iterate through each character in the line .
    for(int i = 0; i <(int)sequence.length();i++)
    {
      if(sequence[i]!='G'&&sequence[i]!='C'&&sequence[i]!='A'&&sequence[i]!='T'&&sequence[i]!='N'){
          throw std::runtime_error("informative error message");
        }
}
    hdr = header;
    seq = sequence;
    }

DNA::DNA(std::ifstream &infile){
        std::string line;
				getline(infile,hdr);
				while(getline(infile,line)){
		//do something with these lines
						seq=seq+line;
				}
infile.close();

 }
	/*
	Getter methods
	*/
	std::string DNA::getSequence(){
    return seq;
  }
	std::string DNA::getHeader(){
    return hdr;
  }

	/*
	Produces FASTA-formatted output as a string,
	with the sequence wrapped to `columns` number of characters (default 80)
	*/
  std::string DNA::toFasta(int columns){
//loop through the seq and have a counter......use <<endl to break the one big string.
std::string fasta;
 fasta = hdr+"\n";
 int counter = 0;
for(int j=0; j<(int) seq.length();j++){
    fasta +=seq[j];

    if(counter==columns-1){
      fasta += "\n";
    }
    else
    {
      counter = 0;
    }
counter++;
  }
  fasta=fasta+"\n";
  return fasta;
}
  /*
	Returns a new DNA object whose `header` is the same as this object's,
	and whose underlying `sequence` is the reverse complement as this object's.
	*/
	DNA DNA::revcomp(){

    std::string result;
    //std::string comp;
    //loop to go through the string.
    for(unsigned int j=0;j<seq.length();j++){
      // if condition to check the reverse compliment od DNA.
        if(seq[j]=='G') result = result + "C";
        else if (seq[j]=='C') result = result + "G";
        else if (seq[j]=='A') result = result + "T";
        else if (seq[j]=='T') result = result + "A";
        else if (seq[j]=='N') result = result+'N';
        else 	exit(EXIT_FAILURE);// exit the loop if user enters any thing else

    }
        //cout << result << endl; //ABC
        reverse(result.begin(), result.end());
        //cout << result << endl; //BCA
        return DNA(hdr,result);

  }
/*
	Searches the sequence for `query`, a string, AND its reverse complement.
	Returns the index of the first instance of `query` or its reverse complement,
	or `string::npos` if not found.
	*/
  // size_t is a type of int .
	size_t DNA::find(std::string query, size_t start){
                start += 1;
                start -= 1;
                DNA querycomp = DNA::DNA(hdr,query);
                std::string rev = querycomp.revcomp().getSequence();
                size_t findrev = seq.find(rev);
                size_t findquery = seq.find(query);
                if( findrev==std::string::npos&&findquery==std::string::npos){
                    return std::string::npos;
                }
                if(findrev<findquery){
                    return findrev;
                }
                else{
                    return findquery;
                }

        }
/*
	the equality operator does not test full equality.
	It returns true if and only if d1 and d2 have the same sequence
	(even if their headers differ), and false otherwise.
	*/
   bool operator==(DNA d1, DNA d2){
  // function check if 2 seqare equal.
        if(d1.getSequence()==d2.getSequence()){
              return true;
        }
        else {
          return false;
        }
   }
