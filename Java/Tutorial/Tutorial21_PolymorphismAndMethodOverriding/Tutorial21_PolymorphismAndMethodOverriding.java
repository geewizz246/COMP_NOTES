package Tutorial21_PolymorphismAndMethodOverriding; // NOTE THAT PACKAGE NAMES USUALLY START WITH LOWERCASE LETTERS

/* POLYMORPHISM
 * This is the ability of similar objects to be treated the same, but also utilise
 * their differences automatically
 */
public class Tutorial21_PolymorphismAndMethodOverriding {
    
    public static void main(String[] args) {
        Shape square = new Shape(10);
        Shape rect = new Shape(12, 36);
        Triangle tri = new Triangle(14, 16);
        Circle circ = new Circle(15);
        Ellipse oval = new Ellipse(8, 3);
        
        
        System.out.println("Area of Square = " + square.Area());
        System.out.println("Area of Rectangle = " + rect.Area());
        System.out.println("Area of Triangle = " + tri.Area());
        System.out.println("Area of Circle = " + circ.Area());
        System.out.println("Area of Ellipse = : " + oval.Area());
    }

}
