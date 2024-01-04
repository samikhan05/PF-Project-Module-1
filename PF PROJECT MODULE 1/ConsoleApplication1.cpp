#include <iostream>
#include <fstream>
#include <string>
#include <ios>
#include <cstdio>

//using namespace std;

// Function declarations
void addproducts();
void viewproducts();
void searchproducts();
void updateproducts();
void deleteproducts();
void viewmenu();
void exitProgram();
int main()
{
	// Infinite loop for menu
	while (true)
	{
		viewmenu(); // Call the main menu function
	}
	return 0;
}

// Function To Display Menu On the screen.
void viewmenu()
{
	// Variable to store the user's menu option
	int option;
	// Prompting the user to enter a menu option.
	std::cout << " Cash and Carry Management System \n" << " 1. Adding the Products. \n" << " 2. Viewing the Products. \n" << " 3. Searching the Products. \n" << " 4. Updating the Products. \n" << " 5. Deleting the Products. \n" << " 6. Exit. \n";
	std::cin >> option;

	// Use a switch statement to perform actions based on the user's choice
	switch (option)
	{
	case 1:
		std::cout << " 1. Adding the Products. " << std::endl;
		addproducts(); // Calling the function For adding products
		break;

	case 2:
		std::cout << " 2. Viewing the Products. " << std::endl;
		viewproducts(); // Calling the function For viewing products
		break;

	case 3:
		std::cout << " 3. Searching the Products. " << std::endl;
		searchproducts(); // Calling the function For searching products
		break;

	case 4:
		std::cout << " 4. Updating the Products. " << std::endl;
		updateproducts(); // Calling the function For updating products
		break;

	case 5:
		std::cout << " 5. Deleting the Products. " << std::endl;
		deleteproducts(); // Calling the function For deleting products
		break;

	case 6:
		std::cout << " Exiting the program." << std::endl;
		exitProgram(); // Calling the function to exit from the program.
		break;
	default:
		std::cout << " Ivalid Function";// Display an error message for an invalid menu option
	}
}

// Function To exit From The system
void exitProgram()
{
	std::cout << " Goodbye!. Have a Nice Day..." << std::endl;
	exit(0);
}

// Function For Deleting the Record From the Inventory
void deleteproducts()
{
	// Declareing an Input File Stream
	std::ifstream fin;
	fin.open("Cash and Carry Management.txt"); // Opening the file for reading

	// Exceptional handling : Checking if the file fails to open.
	try
	{
		if (fin.fail())
		{
			throw std::runtime_error("File Not Found!!!");
		}
	}
	catch (std::runtime_error& e)
	{
		// Declaring an Error Message if the file is not found.
		std::cout << "Exceptional Handling: " << e.what() << std::endl;
		return;
	}

	// Declare variables for reading from the file
	int delete_id, product_id, quantity, price;
	std::string product_name;
	bool recordExists = false; // Flag to track whether the record with the specified ID exists in the file or Inventory.

	// Prompting the user to Enter the ID against which the record to be deleted
	std::cout << "Enter the ID you want to delete: ";
	std::cin >> delete_id;

	// // Opening an output file stream to create an updated file
	std::ofstream deletefile;
	deletefile.open("Updated Recorded Of Cash and Carry Management System.txt");

	// Loop For reading data from the file.
	while (fin >> product_id >> product_name >> quantity >> price)
	{
		// Check if the current line's product_id matches with the ID to be deleted.
		if (product_id == delete_id)
		{
			recordExists = true;// Setting the flag true which indicates that the record with the specified ID exists

			// Display information about the found record
			std::cout << "Record Found with ID " << product_id << "\n"<< "Name: " << product_name << "\n"<< "Price: " << price << "\n"<< "Quantity: " << quantity << "\n";
		}
		else
		{
			// Write the current line to the updated file if the product_id doesn't match the ID to delete
			deletefile << product_id << " " << product_name << " " << quantity << " " << price << std::endl;
		}
	}

	// Check if a record with the specified ID was found
	if (!recordExists)
	{
		std::cout << "Record with ID " << delete_id << " does not exist." << std::endl;
	}
	else
	{
		std::cout << "Record with ID " << delete_id << " has been deleted." << std::endl;
	}

	// Close the input and output files
	fin.close();
	deletefile.close();

	// Remove the original file and rename the updated file
	remove("Cash and Carry Management.txt");
	rename("Updated Recorded Of Cash and Carry Management System.txt", "Cash and Carry Management.txt");
}

// Function For Updating the Record in the Inventory
void updateproducts()
{
	// Declaring input and output file streams
	std::ifstream inputFile;
	inputFile.open("Cash and Carry Management.txt"); // Opening FIle for reading.
	std::ofstream outputFile;
	outputFile.open("Updated Cash and Carry Management.txt"); // Opening file for writing.

	// Declaring variables to store data from the file and for input frim the user.
	int update_id, product_id, quantity, price, update_quantity, update_price, option;
	std::string product_name;
	bool recordExists = false; // Flag to track whether the record with the specified ID exists in the file or Inventory.

	// Prompting the user to enter the ID against which they want to update the record.
	std::cout << "Enter the ID Against which you want to update the record of Entity: ";
	std::cin >> update_id;

	// Reading data from the input file and processing each line.
	while (inputFile >> product_id >> product_name >> quantity >> price)
	{
		// Check if the current line's product_id matches with the ID Against which user want to update the record.
		if (product_id == update_id)
		{
			recordExists = true; // Setting the flag true which indicates that the record with the specified ID exists

			// Displaying Informatin about the Found Record.
			std::cout << "Record Found with ID " << product_id << "\n" << "Name: " << product_name << "\n"<< "Quantity: " << quantity << "\n"<< "Price: " << price << "\n";

			// Prompting the user to choose what to update.
			std::cout << "What do you want to Update" << "\n"<< "1. Quantity " << "\n"<< "2. Price " << "\n";
			std::cin >> option;

			// Using a switch statement to handle user's choice.
			switch (option)
			{
			case 1:
				// Updating the quantity and writing the updated record in the output file.
				std::cout << "Enter the New Quantity of the Product: ";
				std::cin >> update_quantity;
				outputFile << product_id << " " << product_name << " " << update_quantity << " " << price << std::endl;
				break;

			case 2:
				// Updating the price and writing the updated record in the output file.
				std::cout << "Enter the New Price of the Product: ";
				std::cin >> update_price;
				outputFile << product_id << " " << product_name << " " << quantity << " " << update_price << std::endl;
				break;

			default:
				// Display An Error Message for an Invalid Option.
				std::cout << "Invalid Option.";
				break;
			}

			// Displaying a success message after updating the record.
			std::cout << "Record Updated Successfully!!!" << std::endl;
		}
		else
		
			// If the current line's product_id doesn't match the update_id, write the line to the output file unchanged.
			outputFile << product_id << " " << product_name << " " << quantity << " " << price << std::endl;
		}
	}

    // If no record with the specified ID was found, then display a message
	if (!recordExists)
	{
		std::cout << "Record with ID " << update_id << " does not exist." << std::endl;
	}

	// Closing Input and Ouptput Files.
	inputFile.close();
	outputFile.close();

	// Remove the original file and rename the updated file
	remove("Cash and Carry Management.txt");
	rename("Updated Cash and Carry Management.txt", "Cash and Carry Management.txt");
}

// Function to View the Products from the Inventory
void searchproducts()
{
	// Declareing an Input File Stream
	std::ifstream fin;
	fin.open("Cash and Carry Management.txt"); // Opening the file for Reading
	
	// Exceptional handling : Checking if the file fails to open.
    try
	{
		if (fin.fail())
		{
			throw std::runtime_error(" File Not Found!!!");
		}
	}
	catch (std::runtime_error& e)
	{
		// Declaring an Error Message if the file is not found.
		std::cout << " Exceptional Handling : " << e.what() << std::endl;
	}

	// Declaring the variables for storing the details of the product.
	int product_id, product_id_in_file, quantity, price;
	std::string product_name;
	bool found = false; 

	// Prompting the user to enter the ID of the product which need to be search in the inventiry
	std::cout << " Enter the ID You Want To Search : ";
	std::cin >> product_id;

	// Loop to read the data from the file and to find the product with specified ID.
	while (fin >> product_id_in_file >> product_name >> quantity >> price)
	{
		if (product_id_in_file == product_id)
		{
			found = true;
			break;
		}

		// Declaring a std::string variable to Read the rest of the line before moving the file pointer to the next line
		std::string line;
		getline(fin, line);
	}

	// Displaying the search result.
	if (found == true)
	{
		std::cout << " " << "Product : " << product_name << " with " << product_id << " ID exists in the STOCK." << std::endl << " Quantity : " << quantity << std::endl << " Price : " << price << std::endl;
	}
	else
		std::cout << " " << product_id << " ID does not exists in the STOCK." << std::endl;

	// Closing the file after searching.
	fin.close();
}

// Function to View the Products from the Inventory
void viewproducts()
{
	// Declareing an Input File Stream
	std::ifstream fin;
	fin.open("Cash and Carry Management.txt"); // Opening the file for Reading
	
	// Exceptional handling : Checking if the file fails to open.
	try
	{
		if (fin.fail())
		{
			throw std::runtime_error(" File Not Found!!!");
		}
	}
	catch (std::runtime_error& e)
	{ 
		// Declaring an Error Message if the file is not found.
		std::cout << " Exceptional Handling : " << e.what() << std::endl;
	}

	// Declaring the variables for storing the details of the product.
	int product_id, quantity, price;
	std::string product_name;

	// Display header for the Product Details
	std::cout << " Product ID \t Product Name \t Quantity \t Price \n";
	
	// Read the Details of the product from the file and Display them on the Screen.
	while (fin >> product_id >> product_name >> quantity >> price)
	{
		std::cout << "   "  << product_id  << "\t" << "\t  " << product_name << "\t" << "\t  " << quantity << "\t" << "\t  " << price << std::endl;
	}

	// Closing the file after reading it.
	fin.close();
}

// Function to Add Products to the Inventory
void addproducts()
{
	// Declaring variables for storing product details
	int product_id, quantity, price;
	std::string product_name;
	
	std::ofstream fout; // Declaring an output File Stream.
	fout.open("Cash and Carry Management.txt", std::ios::app); // Opening the file in the append mode to add new products
	
	// Prompting the User to Enter the Details of the Product.
	std::cout << " Enter Product Id : "; 
	std::cin >> product_id;
	std::cout << " Enter the Product Name : ";
	std::cin >> product_name;
	std::cout << " Enter the Quantity Of Product You have : ";
	std::cin >> quantity;
	std::cout << " Enter the Price of the Product : ";
	std::cin >> price;

	// Write the Product Details in the File.
	fout << product_id << " " << product_name << " " << quantity << " " << price << std::endl;
	
	// Closing the File.
	fout.close();
}