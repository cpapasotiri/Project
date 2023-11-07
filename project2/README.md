<p align="center"><img src="../logo_el.png" alt="Λογότυπο ΕΚΠΑ DiT" width=50%/></p>

# <center>Ανάπτυξη Λογισμικού για Πληροφοριακά Συστήματα - Project 1 - Χειμερινού Εξαμήνου 2023-2024</center>


## Προσωπικά δεδομένα ομάδας
<table>
    <tr>
    <th>Επώνυμο</th>
    <th>Όνομα</th>
    <th>Αριθμός Μητρώου</th>
    </tr>
    <tr>
    <td>Εζεκελιάν</td>
    <td>Αναΐτ</td>
    <td>1115201900056</td>
    </tr>
    <tr>
    <td>Παπασωτήρη</td>
    <td>Χριστίνα</td>
    <td>1115201900151</td>
    </tr>
</table>

## Compile & Run
    C++
    Use the following commands to compile
        cmake .
        cmake --build . 
        Run the project1 executable with the following command
            ./project1 <filepath> <dimensions> <K>
            e.g. ./project1 ../project1/datasets/2dims.bin 2 2  
            e.g. ./project1 ../project1/datasets/00000020.bin 100 10
        Run the Catch2 Unit Tests with the following command
            ./tests_runner
        
    
## Οργάνωση κώδικα
    project1/
    ├── datasets/
    │   ├── *.bin
    ├── include/
    │   ├── *.hpp
    ├── src/
    │   ├── *.cpp
    ├── templates/
    │   ├── *.tpp
    ├── tests/
    │   └── *_tests.cpp
    └── CMakeLists.txt

## Υλοποίηση
    Δουλέψαμε παράλληλα στα περισσότερα τμήματα της εργασίας. Αναλυτικότερα, η Αναΐτ ασχολήθηκε αποκλειστικά με την υλοποίηση της κλάσης διπλά συνδεδεμένης λίστας  DLL και των tests με τη χρήση του Catch2 framework. Η Χριστίνα ασχολήθηκε αποκλειστικά με την υλοποίηση της κλάσης του γράφου Graph, με το διάβασμα του αρχείου και με το compile του project. Συνεργαστήκαμε για την υλοποίηση του vector, του γράφου και του αλγορίθμου.
