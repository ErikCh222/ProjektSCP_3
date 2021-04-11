# ProjektSCP_3
ProjektSCP_3.cpp : Project for SCP INI config file 

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
        key=1
        key=2
        key=3
        [section2]
        key=1
        key=2
        key=3
        [section3]
        key=1
        key=2
        key=3
    readFileAndPrintINIFile() - will read file from given file path 
    writeNewINIFile() - will write data structure above to file
    
   
