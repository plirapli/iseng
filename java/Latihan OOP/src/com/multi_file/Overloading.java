package com.multi_file;

public class Overloading {
  public static void main(String[] args) {
    // Overloading Constructor
    Player player1 = new Player("Seva");
    Player player2 = new Player();
    Player player3 = new Player();
    Player player4 = new Player("Hekal");

    player1.show();
    player2.show();
    player3.show();
    player4.show();

    // Overloading Method
    int a = Matematika.tambah(1, 19);
    double b = Matematika.tambah(1, 0.98);

    System.out.println(a);
    System.out.println(b);
  }
}
