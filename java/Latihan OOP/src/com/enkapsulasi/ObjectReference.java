package com.enkapsulasi;

// Class Buku
class Buku {
  String judul, penulis;

  Buku(String judul, String penulis) {
    this.judul = judul;
    this.penulis = penulis;
  }

  void display() {
    System.out.println("Judul: " + this.judul);
    System.out.println("Penulis: " + this.penulis);
  }
}

public class ObjectReference {
  public static void main(String[] args) {
    Buku firstBook = new Buku("Tes", "Hekal");
    firstBook.display();

    // Menampilkan address Buku 1
    String addressFirstBook = Integer.toHexString(System.identityHashCode(firstBook));
    System.out.println(addressFirstBook + "\n");

    // Assignment Object
    Buku secondBook = firstBook;
    secondBook.display();

    // Menampilkan address Buku 2
    String addressSecondBook = Integer.toHexString(System.identityHashCode(secondBook));
    System.out.println(addressSecondBook + "\n");

    // Memasukkan object ke dalam method
    fungsi(secondBook);
  }

  public static void fungsi(Buku dataBuku) {
    String addressBook = Integer.toHexString(System.identityHashCode(dataBuku));
    System.out.println(addressBook + "\n");
  }
}
