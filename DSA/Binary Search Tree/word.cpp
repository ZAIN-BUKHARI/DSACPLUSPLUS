#include <iostream>
#include "docx/document.h"

int main() {
    // Create a Word document
    docx::document doc;

    // Add a paragraph to the document
    doc.add_paragraph("Hello, this is a sample paragraph.");

    // Add another paragraph with formatting
    docx::paragraph p2;
    p2.add_run("This is bold and italic.").bold().italic();
    doc.add_paragraph(p2);

    // Save the document to a file
    doc.save("output.docx");

    std::cout << "Document saved successfully." << std::endl;

    return 0;
}
