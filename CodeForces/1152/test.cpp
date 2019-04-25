int main() {
  volatile int a = 0;
  while(a != 1000000000) {
    a ++;
  }
}
