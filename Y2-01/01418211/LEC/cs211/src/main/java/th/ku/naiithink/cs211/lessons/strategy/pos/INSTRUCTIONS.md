# แบบฝึกหัดเรื่อง Design Pattern (Strategy Pattern)

วิชา 01418211 การสร้างซอฟต์แวร์

พิจารณาโปรแกรมขายสินค้า โดยมีการสร้างคลาส `Product` และคลาส `Store` ตามโค้ดด้านล่าง

```java
  public class Product {
        private String name; // ชื่อสินค้า
        private double price; // ราคาสินค้า
        private int quantity; // จํานวนในสต็อคของสินค้านี้
        // ...constructor, getter/setter methods ครบถ้วน...
  }

  public class Store {
        private List<Product> products;

        public Store() { products = new ArrayList<>(); }
        public void addProduct(String name, double price, int quantity) {
            products.add(new Product(name, price, quantity));
        }
        // นับจํานวนสินค้าทั้งหมด ทั้งมีในสต็อคหรือหมดสต็อคแล้ว
        public int countAllProduct() {
            int count = 0;
            for (Product prod : products) {
                count += 1;
            }
            return count;
        }
        // นับจํานวนสินค้าทั้งหมดที่มีเหลืออยู่ในสต็อค
        public int countProductInStock() {
            int count = 0;
            for (Product prod : products) {
                if (prod.getQuantity() > 0)
                    count += 1;
            }
            return count;
        }
        // นับจํานวนในสต็อคของสินค้าทั้งหมด
        public int countProductQuantity() {
            int count = 0;
            for (Product prod : products) {
                count += prod.getQuantity();
            }
            return count;
        }
  }
```

## ตัวอย่างการทํางาน

```java
  Store store = new Store();
  store.addProduct("Big Java", 300, 5);
  store.addProduct("Da Vinci Code”, 120, 0);
  store.addProduct("Python 101", 200, 10);
```

โดย `countAllProduct()` จะคืนค่า 3, `countProductInStock()` จะคืนค่า 2, `countProductQuantity()` จะคืนค่า 15 จะเห็น
ว่าโค้ดนี้มีการนับจํานวนสินค้าในหลากหลายรูปแบบ ทําให้โค้ดซ้ำซ้อนและเพิ่มการนับสินค้าในรูปแบบอื่นได้ยาก

## จง

1. ปรับโค้ดนี้โดยนํา strategy pattern มาช่วย เพื่อลดโค้ดซ้ำซ้อนและปรับเปลี่ยน/เพิ่มการนับจํานวนสินค้าในรูปแบบใด ๆ ได้โดยอาจสร้างเมธอด `public int countProduct(Counter counter)` โดยใช้ Counter เป็น strategy ได้
1. สร้างคลาสที่มีเมธอด `main` เพื่อสร้างออปเจ็คต่าง ๆ แล้วพิมพ์ผลการนับสามรูปแบบที่ให้ทางหน้าจอด้วย
1. วาดแผนภาพ UML เพื่อแสดงถึงโครงสร้างคลาสของโปรแกรมนี้
