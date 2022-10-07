package th.ku.naiithink.cs211.lessons.interfaces.i.ii;

public class Pet
        implements Comparable<Pet> {

    private String name;

    private String type;

    private int age;

    public Pet(String name, String type, int age) {
        this.name = name;
        this.type = type;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public String toString() {
        return "Pet [name=" + name + ", type=" + type + ", age=" + age + "]";
    }

    @Override
    public int compareTo(Pet other) {
        return this.age > other.age ? 1
                                    : this.age == other.age ? 0
                                                            : -1;
    }
}
