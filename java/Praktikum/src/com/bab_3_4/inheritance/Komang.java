package com.bab_3_4.inheritance;

public class Komang extends Musuh {
  Komang(String nama, int nyawa) {
    super(nama, nyawa);
  }

  void darah() {
    System.out.println("Hanya sebesar " + this.nyawa);
  }
}
