#include <iostream>

using namespace std;

int main() {
	int order=1;
    while (true) {
        int totalSacksRejected = 0;
        int totalSacksAccepted = 0;
        double totalWeight = 0;
        int sand = 0, gravel = 0, cement = 0;
		
        // Input the number of sacks for each type for the new order
        int cementCount, gravelCount, sandCount;
        cout<<"              Order "<<order<<endl;
        cout << "Enter the number of cement sacks required: ";
        cin >> cementCount;
        cout << "Enter the number of gravel sacks required: ";
        cin >> gravelCount;
        cout << "Enter the number of sand sacks required: ";
        cin >> sandCount;

        // Calculate total number of iterations based on the sum of entered sack numbers
        int totalIterations = cementCount + gravelCount + sandCount;

        double regularPrice = 0;  // Initialize regularPrice
        double discountPrice = 0;  // Initialize discountPrice
        int specialPacks = 0;  // Initialize specialPacks

        // Process each sack for the new order
        for (int i = 0; i < totalIterations; ++i) {
            char contents;
            cout << "\nProcessing Sack " << i + 1 << ":\n";
            cout << "Enter the contents of Sack " << i + 1 << " (C for cement, G for gravel, S for sand): ";
            cin >> contents;

            // Check if the sack is valid and update counts and weight accordingly
            if (contents == 'S' && sand < sandCount) {
                double weight;

                // Display weight range message for sand
                cout << "Enter the weight of the sand in kilograms (over 49.9 and under 50.1): ";

                while (true) {
                    cin >> weight;

                    // Check weight for sand
                    if (weight >= 49.9 && weight <= 50.1) {
                        cout << "Sack " << i + 1 << " accepted - Contents: S, Weight: " << weight << " kg" << endl;
                        totalWeight += weight;
                        sand++;
                        totalSacksAccepted++;
                        regularPrice += 2;  // Regular price for sand
                        break;  // Valid weight, break out of the loop
                    } else {
                        cout << "Invalid weight for the sand sack" << endl;
                        cout << "Enter a weight within the specified range." << endl;
                    }
                }
            } else if ((contents == 'G' && gravel < gravelCount) || (contents == 'C' && cement < cementCount)) {
                double weight;

                // Display weight range message based on the entered material
                cout << "Enter the weight of the entered material (" << (contents == 'C' ? "cement" : "gravel") << ") in kilograms ";
                cout << "(" << (contents == 'C' ? "over 24.9 and under 25.1" : "over 49.9 and under 50.1") << "): ";

                while (true) {
                    cin >> weight;

                    // Check weight based on contents
                    if ((contents == 'C' && (weight >= 24.9 && weight <= 25.1)) ||
                        (contents == 'G' && (weight >= 49.9 && weight <= 50.1))) {
                        cout << "Sack " << i + 1 << " accepted - Contents: " << contents << ", Weight: " << weight << " kg" << endl;

                        if (contents == 'G') {
                            gravel++;
                            regularPrice += 2;  // Regular price for gravel
                        } else {
                            cement++;
                            regularPrice += 3;  // Regular price for cement
                        }

                        totalWeight += weight;
                        totalSacksAccepted++;
                        break;  // Valid weight, break out of the loop
                    } else {
                        cout << "Invalid weight for the " << (contents == 'C' ? "cement" : "gravel") << " sack" << endl;
                        cout << "Enter a weight within the specified range." << endl;
                    }
                }
            } else {
                cout << "Exceeded the allowed number of " << (contents == 'S' ? "sand" : (contents == 'G' ? "gravel" : "cement")) << " sacks. Sack " << i + 1 << " rejected." << endl;
                totalSacksRejected++;
                totalIterations++;
            }
        }

        // Count the number of special packs
        int minSpecialPacks = min(cement / 1, min(gravel / 2, sand / 2));
        specialPacks += minSpecialPacks;

        // Calculate the discount price
        discountPrice = minSpecialPacks * 10;

        // Output the total weight of the accepted sacks in the order
        cout << "\nTotal weight of the accepted sacks in the order: " << totalWeight << " kg" << endl;

        // Output the number of sacks rejected from the order
        cout << "Number of sacks rejected from the order: " << totalSacksRejected << endl;

        // Output the total number of accepted sacks for each type
        cout << "Total number of accepted cement sacks: " << cement << endl;
        cout << "Total number of accepted gravel sacks: " << gravel << endl;
        cout << "Total number of accepted sand sacks: " << sand << endl;

        // Output the total number of accepted sacks
        cout << "Total number of accepted sacks: " << totalSacksAccepted << endl;

        // Output the regular price for the order
        cout << "Regular price for the order: $" << regularPrice << endl;

        // Check if a discount applies and output the new price and amount saved
        if (specialPacks > 0) {
            cout << "Special pack discount applies! New price for the order: $" << regularPrice - discountPrice << endl;
            cout << "Amount saved: $" << discountPrice << endl;
        } else {
            cout << "No special pack discount applies." << endl;
        }
       

        // Ask if the user wants to add another order
        char addAnotherOrder;
        cout << "\nDo you want to add another order? (y/n): ";
        cin >> addAnotherOrder;
		order++;
		system("cls");
        // Break out of the loop if the user does not want to add another order
        if (addAnotherOrder != 'y' && addAnotherOrder != 'Y') {
        	 
            break;
        }
    }

    return 0;
}

