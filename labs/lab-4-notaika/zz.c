int find_substring(const char *str, const char *substr) {
    // Edge Case: If substring is empty, it's technically found at index 0
    if (*substr == '\0') {
        return 0;
    }

    const char *p_start = str; // Holds the starting position of the check

    // Loop until we reach the end of the main string
    while (*p_start != '\0') {
        const char *p_str = p_start; // Runner for main string
        const char *p_sub = substr;  // Runner for substring

        // Check for match:
        // 1. Strings match at this character
        // 2. Substring hasn't ended yet
        // 3. Main string hasn't ended yet (safety)
        while (*p_str == *p_sub && *p_sub != '\0' && *p_str != '\0') {
            p_str++;
            p_sub++;
        }

        // If p_sub reached the null terminator, we found the full match
        if (*p_sub == '\0') {
            // POINTER ARITHMETIC: Current Start Address - Base Address
            return (int)(p_start - str);
        }

        // Optimization: If the remaining string is shorter than substring, stop (Optional but good)
        // For simplicity in this lab, just moving to the next char is sufficient.
        p_start++;
    }

    return -1; // Not found
}