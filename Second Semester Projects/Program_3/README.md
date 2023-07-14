# Project 3 - Logging Into a Database

### practice with structures, functions, subclasses, hash tables, and chaining

This program deals with a database and its users. The database stores the user's username and an encrypted password. The program reads in data from a .txt file to initialize the databse and then allows the user to either attempt to log in, create an account, delete an account, or quit the program; it verifies the user through input of the user's name and password. We were given an extra file that contained the SHA256 cryptographic hashing algorithm to use when encrypting the users' passwords. All we had to do was implement the function `sha256()` in order to encrypt the password.

The program stores all information on its users in a user-defined hashTable; this hashTable contains buckets that use the username as the key; this is designed specifically so that collisions occur frequently. Collisions in the hashing process are handled through chaining, so each bucket is essentially a list that can be added onto as more entries are processed.

___

**All relevant in-depth documentation for each function is explained in the hashTable.h file.**

The hashTable object contains several attributes and functions that help build the user database. The subclass entry handles a single entry of a user in the database and contains the username, encrypted password, and salt string of the user, as well as  a pointer *\*next* that is used in the chaining process. It also includes a constructor and accessor methods for each attribute. The hashTable class also includes an integer for the size of the database and a pointer array of entry objects that stores the specifics of the database. It also contains several functions:

**private functions** <br />`hash()` - returns the index to the bucket the user will be stored in. This is based off the ASCII value of their username. This function is designed to cause multiple collisions <br />`getEntry()` - accessor for a specific entry in the database

**public functions** <br /> `hashTable()` / `~hashTable()` - constructor and destructor for the hashTable object <br />`generateSalt()` - generates a random string of characters that is added onto the password before hashing to aid in encryption <br />`getSalt()` - accessor for user salt string <br />`addEntry()` - constructs a new entry object and adds it to the hashTable <br />`validateLogin()` - validates the user by their username and hashed password mathc user input <br />`removeUser()` - removes the user from the database and checks if it was successful
