# Website-Analytics
Testing task for company.

How to run this project?
You should download all files and run Website Analytics.sin by using Visual Studio. 
If you haven`t Visual Studio, copy and paste code from main.cpp in your IDE.

Efficiency and Big O Notation
Step-by-Step Analysis
1) Reading Data from Files:
This step involves reading data from files into vectors. Assuming each file has n entries, the time complexity for reading each file is O(n). So, for two files, it is O(n) + O(n) = O(n).

2) Filling the Maps:
This step involves filling two unordered maps with sets of product IDs for each user. Each insertion into a map and a set is O(1) on average. Thus, the time complexity for processing both datasets is O(n) + O(n) = O(n).

3) Processing Users who Visited the Site on Any Day:
This step involves inserting user IDs into a set. Each insertion is O(1) on average. The total time complexity for processing both maps is O(n) + O(n) = O(n).

4) Processing Users who Visited New Pages on the Second Day:
This step involves checking for each user in the second day whether they visited new pages that they did not visit on the first day.
For each user who visited the site on the second day (O(n)), we might need to iterate through their pages (in the worst case, also O(n) times).
However, typically the number of pages per user is much smaller than the total number of users. Let's denote the average number of pages visited by a user as k. Thus, this step can be approximated as O(n * k).

Total Time Complexity
Combining all steps, the total time complexity is:
𝑂(𝑛) + 𝑂(𝑛) + 𝑂(𝑛) + 𝑂(𝑛 ∗ 𝑘) = 𝑂(𝑛) + 𝑂(𝑛 ∗ 𝑘)
Since k is the average number of pages per user and generally much smaller than n, the dominant term is O(n * k). Therefore, the overall time complexity is:
𝑂(𝑛 ∗ 𝑘)

Explanation of Efficiency
1) Reading Data: Efficiently reads data from files with a linear scan, making it O(n).
2) Using Hash Maps and Sets: Allows for average constant time complexity O(1) for insertions and lookups, ensuring efficient processing of user and page data.
3) Iterating Through Users and Pages: By leveraging the fact that k (average pages per user) is typically much smaller than n (total entries), the overall complexity remains manageable.
