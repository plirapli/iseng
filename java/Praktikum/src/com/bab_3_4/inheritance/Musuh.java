package com.bab_3_4.inheritance;

public class Musuh {
  String nama;
  int nyawa;

  Musuh(String nama, int nyawa) {
    this.nama = nama;
    this.nyawa = nyawa;
  }

  void serang() {
    System.out.println(this.nama + " menyerangmu!");
  }
}
