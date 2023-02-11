#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct {
  char symbol[3];
  double mass;
} Element;

// Define an array of all elements
Element elements[] = {
  {"H", 1.0079},
  {"He", 4.0026},
  {"Li", 6.941},
  {"Be", 9.0122},
  {"B", 10.811},
  {"C", 12.0107},
  {"N", 14.0067},
  {"O", 15.9994},
  {"F", 18.9984},
  {"Ne", 20.1797},
  {"Na", 22.9897},
  {"Mg", 24.305},
  {"Al", 26.9815},
  {"Si", 28.0855},
  {"P", 30.9738},
  {"S", 32.065},
  {"Cl", 35.4527},
  {"Ar", 39.948},
  {"K", 39.0983},
  {"Ca", 40.078},
  {"Sc", 44.9559},
  {"Ti", 47.867},
  {"V", 50.9415},
  {"Cr", 51.9961},
  {"Mn", 54.938},
  {"Fe", 55.845},
  {"Co", 58.9332},
  {"Ni", 58.6934},
  {"Cu", 63.546},
  {"Zn", 65.39},
  {"Ga", 69.723},
  {"Ge", 72.64},
  {"As", 74.9216},
  {"Se", 78.96},
  {"Br", 79.904},
  {"Kr", 83.8},
  {"Rb", 85.4678},
  {"Sr", 87.62},
  {"Y", 88.9059},
  {"Zr", 91.224},
  {"Nb", 92.9064},
  {"Mo", 95.94},
  {"Tc", 98},
  {"Ru", 101.07},
  {"Rh", 102.9055},
  {"Pd", 106.42},
  {"Ag", 107.8682},
  {"Cd", 112.411},
  {"In", 114.818},
  {"Sn", 118.71},
  {"Sb", 121.76},
  {"Te", 127.6},
  {"I", 126.9045},
  {"Xe", 131.293},
  {"Cs", 132.9055},
  {"Ba", 137.327},
  {"La", 138.9055},
  {"Ce", 140.116},
  {"Pr", 140.9077},
  {"Nd", 144.24},
  {"Pm", 145},
  {"Sm", 150.36},
  {"Eu", 152.92},
  {"Gd", 157.25},
  {"Tb", 158.9253},
  {"Dy", 162.5},
  {"Ho", 164.9303},
  {"Er", 167.259},
  {"Tm", 168.9342},
  {"Yb", 173.04},
  {"Lu", 175.0},
  {"Hf", 178.49},
  {"Ta", 180.9479},
  {"W", 183.84},
  {"Re", 186.207},
  {"Os", 190.23},
  {"Ir", 192.217},
  {"Pt", 195.078},
  {"Au", 196.9665},
  {"Hg", 200.59},
  {"Tl", 204.3833},
  {"Pb", 207.2},
  {"Bi", 208.9804},
  {"Po", 209},
  {"At", 210},
  {"Rn", 222},
  {"Fr", 223},
  {"Ra", 226},
  {"Ac", 227},
  {"Th", 232.0381},
  {"Pa", 231.0359},
  {"U", 238.0289},
  {"Np", 237},
  {"Pu", 244},
  {"Am", 243},
  {"Cm", 247},
  {"Bk", 247},
  {"Cf", 251},
  {"Es", 252},
  {"Fm", 257},
  {"Md", 258},
  {"No", 259},
  {"Lr", 262},
  {"Rf", 261},
  {"Db", 262},
  {"Sg", 266},
  {"Bh", 264},
  {"Hs", 277},
  {"Mt", 268},
};


int main()
{
  char compound[100],element[10],elename[10];
  char again;
  int i=0,k=0,count=0;
  double tmass=0,emass,elemass[20];
  
  printf("~~~~welcome to shamim's micro-project molecular mass calculator~~~~\n\n");
  
  do {
    printf("\t\tinput compound molecule	 = ");
    scanf("%s",compound);
  
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
    
    i = 0;
    tmass = 0;
    
    while(i<strlen(compound)) {
      
      if (isupper(compound[i]) && islower(compound[i+1])) {
        strncpy(element, &compound[i], 2);
        element[2] = '\0';
        
        i++;
      } else {
        strncpy(element, &compound[i], 1);
        element[1] = '\0';
      }
  
      for (int j = 0; j < sizeof(elements) / sizeof(Element); j++) {
        if (strcmp(element, elements[j].symbol) == 0) {
          int multiplier = 1;
          if (isdigit(compound[i + 1])) {
            multiplier = compound[i + 1] - '0';
            i++;
          }
   
         
          printf("|  Element: %s%d Mass: %.2lf\t\t\t\t\t\t|\n", element, multiplier,elements[j].mass * multiplier);
          emass=elements[j].mass * multiplier;
    
        }
      }
      tmass = tmass+emass;
      i++;
    }
    
    printf("|  total mass of the molecule is=%.2f \t\t\t|\n",tmass);
    
  i = 0;
    
    while(i<strlen(compound)) {
      
      if (isupper(compound[i]) && islower(compound[i+1])) {
        strncpy(element, &compound[i], 2);
        element[2] = '\0';
        
        i++;
      } else {
        strncpy(element, &compound[i], 1);
        element[1] = '\0';
      }
  
      for (int j = 0; j < sizeof(elements) / sizeof(Element); j++) {
        if (strcmp(element, elements[j].symbol) == 0) {
          int multiplier = 1;
          if (isdigit(compound[i + 1])) {
            multiplier = compound[i + 1] - '0';
            i++;
          }
          
        elemass[k]=elements[j].mass*multiplier;
         
          printf("|  percentage of element: %s%d Mass: %.2lf\t\t|\n", element, multiplier,((elements[j].mass * multiplier)/tmass)*100);
    
        }
      }
     
      i++;
    }
    
    printf("\n ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
    
    printf("\n\ndo you want to calculate another compound molecule	? (y/n)\n");
    scanf(" %c",&again);
  } while (again == 'y');
  
  return 0;
}
