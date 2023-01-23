package com.latihan_satu;

// Player
class Player {
  String name;
  double health;
  int level;

  // Object member
  Weapon weapon;
  Armor armor;

  // Constructor
  Player(String name, double health) {
    this.name = name;
    this.health = health;
  }

  void equipWeapon(Weapon weapon) {
    this.weapon = weapon;
  }

  void equipArmor(Armor armor) {
    this.armor = armor;
  }

  void attack(Player opponent) {
    double opponentDamageTaken = this.weapon.damage;
    double opponentDefense = opponent.armor.defense;

    String outPlayerDamage = " (" + opponentDamageTaken + ")";
    String outOpponentDefense = " (" + opponentDefense + ")";

    System.out.println(
        this.name + outPlayerDamage + " attacking " +
            opponent.name + outOpponentDefense + "!");

    opponent.defend(opponentDamageTaken);
    System.out.println();
  }

  void defend(double damage) {
    // Taking total damage
    double totalDmg = 0;
    double armorDefense = this.armor.defense;

    if (armorDefense < damage) {
      totalDmg = damage - armorDefense;
    }
    this.health -= damage;

    System.out.println(this.name + " got " + totalDmg + " damage!");
  }

  void display() {
    System.out.println("Name: " + this.name);
    System.out.println("Health: " + this.health + " HP");

    this.weapon.display();
    this.armor.display();
  }
}

// Weapon
class Weapon {
  String name;
  double damage;

  Weapon(String name, double damage) {
    this.name = name;
    this.damage = damage;
  }

  void display() {
    System.out.println("Weapon: " + this.name + ", Damage: " + this.damage + " dps");
  }
}

// Armor
class Armor {
  String name;
  double defense;

  Armor(String name, double defense) {
    this.name = name;
    this.defense = defense;
  }

  void display() {
    System.out.println("Armor: " + this.name + ", Defense: " + this.defense + "\n");
  }
}

public class App {
  public static void main(String[] args) {
    // Make new Player
    Player player1 = new Player("Seva", 100);
    Player player2 = new Player("Hekal", 100);

    // Make new Weapon
    Weapon copperSword = new Weapon("Copper Broadsword", 14);
    Weapon tinSword = new Weapon("Tin Shortsword", 15.5);

    // Make new Armor
    Armor copperArmor = new Armor("Copper Armor", 11);
    Armor tinArmor = new Armor("Tin Armor", 10.5);

    // Equip Player 1
    player1.equipWeapon(copperSword);
    player1.equipArmor(copperArmor);
    player1.display();

    // Equip Player 2
    player2.equipWeapon(tinSword);
    player2.equipArmor(tinArmor);
    player2.display();

    // War
    System.out.println("Let's Battle!");
    player1.attack(player2);
    player2.attack(player1);

    System.out.println("Player Stats:");
    player1.display();
    player2.display();
  }
}
