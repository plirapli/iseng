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

public class LatihanSatu {
  public static void main(String[] args) {
    // Make new Player
    Player player1 = new Player("Seva", 100);
    Player player2 = new Player("Hekal", 100);

    // Make new Weapon
    Weapon copperSword = new Weapon("Copper Broadsword", 15);
    Weapon zenith = new Weapon("Zenith", 225);

    // Make new Armor
    Armor copperArmor = new Armor("Copper Armor", 11);
    Armor solarArmor = new Armor("Solar Armor", 84);

    // Equip Player 1
    player1.equipWeapon(copperSword);
    player1.equipArmor(copperArmor);
    player1.display();

    // Equip Player 2
    player2.equipWeapon(zenith);
    player2.equipArmor(solarArmor);
    player2.display();
  }
}
