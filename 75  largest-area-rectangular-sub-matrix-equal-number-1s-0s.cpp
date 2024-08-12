// to store the final outputs
int finalLeft, finalRight, finalTop, finalBottom;
finalLeft = finalRight = finalTop = finalBottom = -1;
int maxArea = 0;

// Set the left column
for (int left = 0; left < col; left++) {
	// Initialize all elements of temp as 0
	memset(temp, 0, sizeof(temp));

	// Set the right column for the left column
	// set by outer loop
	for (int right = left; right < col; right++) {
		// Calculate sum between current left
		// and right for every row 'i'
		// consider value '1' as '1' and
		// value '0' as '-1'
		for (int i = 0; i < row; i++)
			temp[i] += mat[i][right] ? 1 : -1;

		// Find largest subarray with 0 sum in
		// temp[]. The subArrWithSumZero() function
		// also sets values of finalTop, finalBottom,
		// finalLeft and finalRight if there exists
		// a subarray with sum 0 in temp
		if (subArrWithSumZero(temp, startRow, endRow,
							row)) {
			int area = (right - left + 1)
					* (endRow - startRow + 1);

			// Compare current 'area' with previous area
			// and accordingly update final values
			if (maxArea < area) {
				finalTop = startRow;
				finalBottom = endRow;
				finalLeft = left;
				finalRight = right;
				maxArea = area;
			}
		}
	}
}

// if true then there is no rectangular submatrix
// with equal number of 1's and 0's
if (maxArea == 0)
	cout << "No such rectangular submatrix exists:";

// displaying the top left and bottom right boundaries
// with the area of the rectangular submatrix
else {
	cout << "(Top, Left): "
		<< "(" << finalTop << ", " << finalLeft << ")"
		<< endl;

	cout << "(Bottom, Right): "
		<< "(" << finalBottom << ", " << finalRight
		<< ")" << endl;

	cout << "Area: " << maxArea << " sq.units";
}
