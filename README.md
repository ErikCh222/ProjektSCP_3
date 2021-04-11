# Project SCP_3

School project for managing configuration data structure of .ini files 

Expected functionality:
   - create data structure for .INI file
   - ability to create/update new sections, keys in data structure
       - no duplicated sections
       - no duplicated keys in section
       - able to create single section or key
       - able assing keyValue to given key and section
       - using INIData.createKeyInsection/setKeyValueInSection - if section or key doesnt exist it will be created
   - retrieving data from data structure
       - if given section or key doesnt exit - return empty
   - operator for redirecting data to output
   - operator for meging to data structures
   - read .INI files - may throw FileOperationException, ignoring comments inside .INI file
   - write .INI files - may throw FileOperationException - rewrite existing data in file

    Demonstration functions:

    createNewAndPrintDataStructure() - will create and print new DataStructure of format

[section1]

key1=value1

key2=value2

key3=value3

[section2] 

key1=1

key2=2

key3=3

[section3] 

key1=value1

key2=value2

key3=value3

    readFileAndPrintINIFile() - will read file from given file path 
    writeNewINIFile() - will write data structure above to file
    
    createNewDataStructure() - will create INIdata - showing how you create data inside     
