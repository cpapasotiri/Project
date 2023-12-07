<p align="center"><img src="logo_el.png" alt="Λογότυπο ΕΚΠΑ DiT" width=50%/></p>

# <center>Ανάπτυξη Λογισμικού για Πληροφοριακά Συστήματα - Project - Χειμερινού Εξαμήνου 2023-2024</center>


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
    Use the following commands to compile:
        cmake .
        cmake --build . 
        Run the project executable with the following command:
            ./project <filepath> <dimensions> <K> <distance type e or m>
            e.g. ./project datasets/2dims.bin 2 2 e
            e.g. ./project datasets/00000020.bin 100 10 m
        Run the brute force executable with the following command:
            ./brute_force <filepath> <dimensions> <K> <distance type e or m>

    Use the the following commands to run Catch2 Unit Tests:
        Run the tests executable with the following command:            
            ./allTests
        Run to see tests in detail:
            make run_tests

    Use the following command to clean build files:
        make clean_all  
    
## Οργάνωση κώδικα
    Project/
    ├── datasets/
    │   ├── *.bin
    ├── include/
    │   ├── *.hpp
    ├── src/
    │   ├── brute_force/
    │   │   ├── *.cpp
    │   ├── common/
    │   │   ├── *.cpp
    │   ├── project/
    │   │   ├── *.cpp
    ├── templates/
    │   ├── *.tpp
    ├── tests/
    │   └── *_tests.cpp
    └── CMakeLists.txt
    └── clean.cmake

## Υλοποίηση
    Δουλέψαμε παράλληλα στα περισσότερα τμήματα της εργασίας. 
    Αναλυτικότερα, η Αναΐτ ασχολήθηκε αποκλειστικά με την υλοποίηση της κλάσης διπλά συνδεδεμένης λίστας  DLL και των tests με τη χρήση του Catch2 framework. 
    Η Χριστίνα ασχολήθηκε αποκλειστικά με την υλοποίηση της κλάσης του γράφου Graph, με το διάβασμα του αρχείου και με το compile του project. 
    Συνεργαστήκαμε για την υλοποίηση του vector, του γράφου και του αλγορίθμου.

### Βελτιστοποιήσεις
- Local Join 
- Incredimental Search
- Πρόωρος Τερματισμός
- Χειρισμός δεδομένων αυθαίρετου αριθμού διαστάσεων
- Χειρισμός δεδομένων αυθαίρετου αριθμού αντικειμένων
- Δυνατότητα εύρεσης των k εγγύτερων γειτόνων για ένα ή για όλα τα μέλη του συνόλου
- Δυνατότητα χρήσης εναλλακτικής μετρικής ομοιότητας (π.χ. Euclidean, Manhattan απόσταση κ.α.)