package com.bab_3_4.exception;

class Pembagian {
  public static void main(String[] args) {
    int a = 0;
    int b = 0;
    int c = 0;

    try {
      a = Integer.parseInt(args[0]);
      b = Integer.parseInt(args[1]);

      System.out.println("Nilai a: " + a);
      System.out.println("Nilai b: " + b);
      c = a / b;
    } catch (NumberFormatException error) {
      System.out.println("\nBukan angka. Inisialisasi dengan nilai 0 \n");
    } catch (ArithmeticException error) {
      System.out.println("\nPembagi tidak boleh 0");
      System.out.println("Inisialisasi b dengan nilai 1");

      b = 1;
      // karena terjadi exception maka harus
      // dilakukan pembagian lagi
      c = a / b;
    } finally {
      System.out.println("\nNilai a: " + a);
      System.out.println("Nilai b: " + b);
      System.out.println("Hasil: " + c);
    }
    System.out.println("\nSelesai");
  }
}
