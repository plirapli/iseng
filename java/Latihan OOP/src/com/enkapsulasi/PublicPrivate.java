package com.enkapsulasi;

class Player {
  String name; // Default = Bisa r/w dari luar class
  public int exp; // Public = Bisa r/w dari luar class
  private int health; // Private = Bisa r/w dari dalam class saja

  Player(String name, int exp, int health) {
    this.name = name;
    this.exp = exp;
    this.health = health;
  }

  // Default modifier access
  void display() {
    addExp(); // Mengakses private method
    System.out.println("\nName: " + this.name);
    System.out.println("Exp: " + this.exp);
    System.out.println("Health: " + this.health);
  }

  // Public
  public void changeName(String newName) {
    this.name = newName;
  }

  // Private
  private void addExp() {
    this.exp += 100;
  }
}

public class PublicPrivate {
  public static void main(String[] args) {
    Player player1 = new Player("Hekal", 0, 100);

    // Default
    System.out.println(player1.name); // Membaca data
    player1.name = "Seva"; // Menulis data
    System.out.println(player1.name); // Membaca data

    // Public
    System.out.println(player1.exp); // Membaca data
    player1.exp = 20; // Menulis data
    System.out.println(player1.exp); // Membaca data

    // // Private (Cannot be accessed)
    // System.out.println(player1.health); // Membaca data
    // player1.health = 80; // Menulis data
    // System.out.println(player1.health); // Membaca data

    // Default Method
    player1.display();

    // Public Method
    player1.changeName("Syaikul");
    player1.display();

    // // Private Method (Cannot be accessed)
    // player1.addExp();
  }
}
