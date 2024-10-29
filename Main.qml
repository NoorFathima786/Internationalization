import QtQuick

Window {
  width: Screen.width
  height: Screen.height
  visible: true
  title: StringIDs.string_id_demo_title

  Rectangle {
    anchors.fill: parent
    border.color: "yellow"
    border.width: 2

    Column {
      anchors.centerIn: parent
      spacing: 10

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_dialog_text_enrollment_form
      }

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_name
      }

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_date_of_birth
      }

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_address
      }

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_mobileno
      }

      Text {
        font.pixelSize: 28
        font.bold: true
        text: StringIDs.string_id_pincode
      }
    }
  }
}
