/* run.config
   OPT: -ltl tests/ltl_to_acsl/test_switch3.ltl -ltl-test 1 -ltl-acceptance
*/

/* Calcul de la longueur cumulee des chaines de caracteres prises en parametre */

/* Calcul de la longueur d'une chaine */
int countOne(char* argv) {
  int r=0;
  
  switch (argv[0]) {
  case 0: return 0; 
  case 1:
  case 2:
  case 3:
  default: 
    r++; 
    r+=countOne(argv+1); 
  } 
  return r;
}

/* Somme de chacune des longueurs */
int count(int argc, char** argv) {
  if (argc>0) return countOne(argv[0])+count(argc-1,argv+1);
  return 0;
}

int main(int argc, char** argv) {
  int somme;
  somme=count(argc,argv);
  return 1;
}