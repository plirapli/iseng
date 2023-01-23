package com.dasar;

class Mahasiswa {
  // Data Member
  String nama, NIM;

  // Constructor
  Mahasiswa(String nama, String NIM) {
    this.nama = nama;
    this.NIM = NIM;
  }

  // Method w/o return & w/o param
  void show() {
    System.out.println("Halo " + this.nama + ", NIM " + this.NIM);
  }

  // Method w/o return & w/ param
  void setNama(String nama) {
    this.nama = nama;
  }

  // Method w/ return & w/o param
  String getNama() {
    return this.nama;
  }

  String getNIM() {
    return this.NIM;
  }

  // Method w/ return & w/ param
  String sayHi(String msg) {
    return "Pesan: " + msg;
  }
}

class Dosen {
  String nama;

  Dosen(String nama) {
    this.nama = nama;
  }
}

public class App {
  public static void main(String[] args) throws Exception {
    Mahasiswa mhs1 = new Mahasiswa("Rafli", "123210078");

    // Method
    mhs1.show();
    mhs1.setNama("Haikal");
    mhs1.show();

    System.out.println(mhs1.getNama());
    System.out.println(mhs1.getNIM());

    String msg = "This is a message.";
    System.out.println(mhs1.sayHi(msg));

    Dosen dosen1 = new Dosen("Norvido");
    System.out.println(dosen1.nama);
  }
}
