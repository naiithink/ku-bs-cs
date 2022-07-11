/*
 * There MUST be only one overriding method.
 */

public class Student {
    private String name;
    private int age;
    private String id;

    public Student(String name, int age, String id) {
        this.name = name;
        this.age = age;
        this.id = id;
    }

    public Student(String name, int age) {
        // Invokes the constructor
        this(name, age, "");
    }

    public Student(String name, String id) {
        // Invokes the constructor
        this(name, 0, id);
    }

    @Override
    public String toString() {
        return "Student{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", id='" + id + '\'' +
                '}';
    }
}
