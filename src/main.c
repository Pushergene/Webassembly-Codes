#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
#include <iostream>

using namespace std;

void teppich()
{
  int ebayteppich = 923823;
  printf("Teppich: %d \n", ebayteppich);
  if (ebayteppich < -1) {
      printf("Alter, was geht da ab?!");
  }
  else {
      printf("Okay, geht klar!");
  }
}

void firefox() {
    string Frage = "Was für eine Version hat dein Firefox?";
    string Firefox;
    scanf(Firefox)
    if(Frage < 78) {
        printf("Dein Firefox ist sicher.", Frage);
    }
    else if (Firefox > 78) {
        printf("Du hast eine instabile Firefox version.");
    }
    else if (Firefox > 68 && Firefox < 69) {
        printf("Dein Firefox hat LTS, LongTimeSupport");
}
    else {
        printf("Bitte überleg dir, ob du unsicher surfen willst.");
    }
}

int main() {
    teppich();
    
}
}
