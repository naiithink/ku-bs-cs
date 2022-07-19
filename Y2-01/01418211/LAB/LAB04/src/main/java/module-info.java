module ku.cs.lab04 {
    requires javafx.controls;
    requires javafx.fxml;


    opens ku.cs.lab04 to javafx.fxml;
    exports ku.cs.lab04;

    exports ku.cs.lab04.shop.controllers;
    opens ku.cs.lab04.shop.controllers to javafx.fxml;
}
