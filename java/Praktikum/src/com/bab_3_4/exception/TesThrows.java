package com.bab_3_4.exception;

import java.util.Scanner;

class TesThrows {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    System.out.print("Masukkan inputan: ");
    String input = sc.next();

    try {
      if (input.equals("Java")) {
        throw new RuntimeException(input + " dilempar");
      } else {
        System.out.println(input + " tidak dilempar");
      }
      System.out.println("Maka tulisan ini muncul");
    } catch (RuntimeException err) {
      System.out.println(input + " ditangkap di sini");
      System.out.println(err);
    }
  }
}
