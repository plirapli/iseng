// [CONSTRUCTOR FUNCTION]
// function Person(firstName, lastName) {
//   this.firstName = firstName;
//   this.lastName = lastName;
//   this.sayHello = (name) => {
//     console.log(`Hello ${name}, my name is ${this.firstName}`);
//   };
// }

// Person.prototype.run = () => {
//   console.log(`${this.firstName} is running`);
// };

// const eko = new Person('Eko', 'Joko');
// // eko.sayHello('Joko');
// eko.run();
// console.log(eko);

// [CONSTRUCTOR INHERITANCE]
// function Employee(firstName) {
//   this.firstName = firstName;
//   this.sayHello = (name) => {
//     console.log(`Hello ${name}, my name is ${this.firstName}`);
//   };
// }

// function Manager(firstName, lastname) {
//   this.lastName = lastname;
//   Employee.call(this, firstName);
// }

// const eko = new Manager('Eko', 'Khoir');

// [CLASS]
// class Employee {
//   constructor(firstName) {
//     this.firstName = firstName;
//   }

//   sayHello(name) {
//     console.log(`Hallo, ${name}! Saya employee ${this.firstName} 😁`);
//   }
// }

// class Manager extends Employee {
//   constructor(firstname, lastName) {
//     super(firstname);
//     this.lastName = lastName;
//   }

//   sayHello(name) {
//     console.log(
//       `Hallo, ${name}! Saya manager ${this.firstName} ${this.lastName} 😁`
//       );
//     }
//   }

//   const eko = new Employee('Eko');
//   eko.sayHello('Andi');
//   // console.info(eko);

// const budi = new Manager('Budi', 'Tabuti');
// budi.sayHello('Joko');

// [CLASS SUPER METHOD]
class Orang {
  constructor(name) {
    this.name = name;
  }
  perkenalan() {
    console.log(`Saya ${this.name}`);
  }
}

class Pekerja extends Orang {
  constructor(name, pekerjaan) {
    super(name);
    this.pekerjaan = pekerjaan;
  }

  sayPekerjaan() {
    super.perkenalan();
    console.log(`Saya bekerja sebagai ${this.pekerjaan}`);
  }
}

const budi = new Pekerja('Budi', 'Programmer');
budi.sayPekerjaan();
