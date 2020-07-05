#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
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
    char Frage[] = "Was für eine Version hat dein Firefox?\n";
    int Firefox;
    Firefox = getchar( );
    if(Firefox == 78) {
        printf("Dein Firefox ist sicher.\n", Frage);
    }
    else if (Firefox > 78) {
        printf("Du hast eine instabile Firefox version.\n");
    }
    else if (Firefox > 68 && Firefox < 69) {
        printf("Dein Firefox hat LTS, LongTimeSupport\n");
}
    else {
        printf("Bitte überleg dir, ob du unsicher surfen willst.\n");
    }
}

int main() {
    teppich();
    firefox();
}

/* External function that is implemented in JavaScript. */
extern void putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}
