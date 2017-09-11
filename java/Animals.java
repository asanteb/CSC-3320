import java.io.*;

public class Animals {

    int age;

    double weight;
    double height;

    String gender;        
    String color;
    String type;
    String name;
    String note;

    String langiuage() {
        if (this.type == "DOG") {
            return "Roof Bark Roof";
        }
        else if (this.type == "CAT") {
            return "Meow Mewww Meow";
        }
        else {
            return "Alien growling noises";
        }
    }
    public void setAge     (int a)    { this.age    = a; }
    public void setWeight  (double w) { this.weight = w; }
    public void setHeight  (double h) { this.height = h; }
    public void setType    (String t) { this.type   = t; }
    public void setName    (String n) { this.name   = n; }
    public void setColor   (String c) { this.color  = c; }
    public void setGender  (String g) { this.gender = g; }
    public void setNote    (String n) { this.note   = n; }

    //super
    public static void main(String []args) {

    Animal poo = new Creep();
    poo.setAge(2);
    System.out.println(poo.age);
    }
}
public class Dog extends Animals {
        public static void main(String []args) {

        Animal poo = new Creep();
        poo.setAge(2);
        System.out.println(poo.age);
    }
}
public class Cat extends Animals {
    
}