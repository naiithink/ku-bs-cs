package EX05;

public class Player implements Cloneable, Comparable {
    private String name;
    private int health;
    private int level;

    public Player(String name, int health, int level) {
        this.name = name;
        this.health = health;
        this.level = level;
    }

    public void setName(String new_name) {
        this.name = new_name;
    }

    public int compareTo(Object o) {
        Player ply = (Player) o;
        int diff = this.health - ply.health;
        return diff > 0 ? 1
                        : diff == 0 ? 0
                                    : -1;
    }

    @Override
    public String toString() {
        return name;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
