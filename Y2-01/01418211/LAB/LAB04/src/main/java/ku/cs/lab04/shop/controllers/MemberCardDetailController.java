package ku.cs.lab04.shop.controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import ku.cs.lab04.shop.models.MemberCard;

public class MemberCardDetailController {

    // controller เชื่อมต่อกับ model เพื่อเก็บข้อมูลและนำข้อมูลมาแสดงผลที่ view
    private MemberCard memberCard;

    @FXML
    private Label nameLabel;

    @FXML
    private Label phoneLabel;

    @FXML
    private Label pointLabel;

    @FXML
    private Label cumulativePurchaseLabel;

    @FXML
    private TextField purchaseTextField;

    @FXML
    private TextField pointTextField;

    @FXML
    public void initialize() {
        // initialize จะถูกเรียกใช้เมื่อมีการ load Controller นี้
        System.out.println("initialize MemberCardDetailController");
        memberCard = new MemberCard("Potsawat T.", "64-1045-1199");
        showMemberCardData();
    }

    private void showMemberCardData() {
        nameLabel.setText(memberCard.getName());
        phoneLabel.setText(memberCard.getPhone());
        String cumulativePurchase = String.format("%.2f", memberCard.getCumulativePurchase());
        cumulativePurchaseLabel.setText(cumulativePurchase);
        String point = "" + memberCard.getStamp();
        pointLabel.setText(point);
    }

    @FXML
    public void handleAddPurchaseButton(ActionEvent actionEvent) {
        String input = purchaseTextField.getText();
        double purchase = Double.parseDouble(input);
        memberCard.addPurchase(purchase);
        showMemberCardData();
        purchaseTextField.clear();
    }

    @FXML
    public void handleUsePointButton(ActionEvent actionEvent) {
        String input = pointTextField.getText();
        int point = Integer.parseInt(input);
        memberCard.useStamp(point);
        showMemberCardData();
        pointTextField.clear();
    }
}
