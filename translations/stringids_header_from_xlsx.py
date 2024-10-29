import os
import re
import openpyxl

def generate_header(strings, header_path):
    with open(header_path, 'w', encoding='utf-8') as file:
        file.write("#ifndef STRINGIDS_H\n")
        file.write("#define STRINGIDS_H\n\n")
        file.write("#include <QObject>\n")
        file.write("#include <QQmlEngine>\n\n")
        file.write("class StringIDs : public QObject\n")
        file.write("{\n")
        file.write("    Q_OBJECT\n")
        file.write("    QML_ELEMENT\n")
        file.write("    QML_SINGLETON\n\n")
        
        for string_id in sorted(strings):
            prop_name = string_id.lower()
            file.write(f"    Q_PROPERTY(QString {prop_name} READ {prop_name} NOTIFY localeChanged)\n")
        
        file.write("\n    Q_DISABLE_COPY(StringIDs)\n")
        file.write("    explicit StringIDs(QObject *parent = nullptr)\n")
        file.write("        : QObject(parent)\n")
        file.write("    {}\n\n")
        file.write("public:\n")
        file.write("    static StringIDs &instance()\n")
        file.write("    {\n")
        file.write("        static StringIDs staticInstance;\n")
        file.write("        return staticInstance;\n")
        file.write("    }\n\n")
        file.write("    static StringIDs *create(QQmlEngine *, QJSEngine *)\n")
        file.write("    {\n")
        file.write("        StringIDs *instance = &(StringIDs::instance());\n")
        file.write("        QJSEngine::setObjectOwnership(instance, QJSEngine::CppOwnership);\n")
        file.write("        return instance;\n")
        file.write("    }\n\n")
        
        for string_id in sorted(strings):
            prop_name = string_id.lower()
            file.write(f"    QString {prop_name}() const\n")
            file.write("    {\n")
            file.write(f"        //% \"{string_id}\"\n")
            file.write(f"        return qtTrId(\"{string_id}\");\n")
            file.write("    }\n\n")
        
        file.write("signals:\n")
        file.write("    void localeChanged();\n")
        file.write("};\n\n")
        file.write("#endif // STRINGIDS_H\n")

def main():
    header_path = "../stringids.h"  # Set this to the desired output header file path
    
    # Load the workbook
    file_path = "translations.xlsx"
    workbook = openpyxl.load_workbook(file_path)

    # Select the sheet
    sheet_name = "MessageStrings"  # Change this to the name of the sheet you want to read from
    sheet = workbook[sheet_name]

    # Read all the strings from column A
    strings = set()
    for row in sheet.iter_rows(min_row=3, min_col=1, max_col=1, values_only=True):
        if row[0] is not None and row[0].startswith("string_id_") and ' ' not in row[0]:
            strings.add(row[0].lower())

    generate_header(strings, header_path)

if __name__ == "__main__":
    main()
