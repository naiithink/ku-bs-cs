public class Student {
    // Primitives: `=` assignment
    // except: String
    private String name;
    private int age;
    private String id;

    // `this': scope specifier
    public Student(String name, int age, String id) {
        this.age = age;
        this.name = name;
        this.id = id;
    }

    void learning(String course) {
        System.out.println(course);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        if (age >= 1)
            this.age = age;
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
