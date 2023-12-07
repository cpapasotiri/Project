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

### 1o παραδοτέο:
    Αρχικά δημουργούνται τα vertexes, ένα για κάθε σημείο του αρχείου που διαβάζουμε. Στη συνέχεια μέσω της συνάρτησης add_edges δημιουργούνται οι Κ τυχαίοι γείτονες για κάθε γείτονα. Στην λίστα των γειτόνων κάθε vertex, μπαίνουν και οι reversed γείτονες. Η συνάρτηση NNDescend αποθηκεύει σε έναν πίνακα από ζευγάρια (απόσταση από ένα vertex, 2ο vertex) τόσο του άμεσους γείτονες, όσο και τους γείτονες των γειτόνων τους. Στη συνέχεια κάνει sort των πίνακα και εισάγει τα vertexes ,αν δεν υπάρχουν ήδη, στη λίστα των γειτόνων. Στην περίπτωση που η λίστα έχει περισσότερα από Κ vertexes, ελέγχει αν αυτά ανήκουν στους Κ εγκύτερους γείτονες και αν όχι, τα αφαιρεί από τη λίστα. Η διαδικασία αυτή επαναλαμβάνεται για όλα τα vertexes του γράφου και αν τελικά δεν υπάρχουν αλλαγές, σταματάει. 

### 2ο παραδοτέο:
#### Βελτιστοποιήσεις:
1. Local Join
    Η συνάρτηση nnDescend για τους άμεσους γείτονες, λειτουρεί όπως και στο 1ο παραδοτέο. Για τους γείτονες των γειτόνων, εξετάζει αν κάποιος από τους υπόλοιπους γείτονες του vertex στο οποίο βρισκόμαστε είναι εγκύτερος από αυτούς που ήδη υπάρχουν στη λίστα των γειτόνων του και τον προσθέτει σε αυτήν. Την ευθύνη για την αφαίρεση των επιπλέον γειτόνων έχει η διαδικασία για τον συγκεκριμένο vertex. 
2. Σταδιακή Αναζήτηση (Incrimental search) 
    Στον κόμβο της λίστας, έχει προσθετεί ένα boolean flag το οποίο αρχικοποιείται σε true μέσα στην add_edges όταν προστίθεται σε κάποια λίστα, τόσο ως άμεσως όσο και ως reversed γείτονας. Στη συνέχεια, πριν την εκτέλεση του Local Join ελέγχεται αν τουλάχιστον 1 από τα δύο vertexes έχει τη σημαία του true και στο τέλος της διαδικασίας, αλλάζει την τιμή της σημαίας σε false.
3. Πρόωρος Τερματισμός
    Σε αντίθεση με το 1ο παραδοτέο, στο 2ο η συνθήκη για τη while δεν είναι να συνεχίζει όταν δεν υπάρχει καμία αλλάγή, αλλά μόνο για όσο οι αλλαγές είναι περισσότερες από 10. 