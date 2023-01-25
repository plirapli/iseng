package com.multi_file;

public class Player {
  private String name;
  private static int numOfPlayer = 0;

  // Overloading Constructor
  // Option 1:
  Player(String name) {
    this.name = name;
  }

  // Option 2:
  Player() {
    Player.numOfPlayer++;
    this.name = "Player " + Player.numOfPlayer;
  }

  void show() {
    System.out.println("Name: " + this.name);
  }
}
