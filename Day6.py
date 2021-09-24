#100daysofcodewithGFG
# code by @vaibhav123v
#Driver Code Starts
#Initial Template for Python 3

 # } Driver Code Ends
#User function Template for python3

class Solution:
    def checktree(self, preorder, inorder, postorder, N): 
    
        # if the array lengths are 0, then all of them are obviously equal 
        if N == 0: 
            return 1
            
        # if array lengths are 1, then check if all of them are equal 
        if N == 1: 
            return (preorder[0] == inorder[0]) and (inorder[0] == postorder[0]); 
    
        # search for first element of preorder in inorder array 
        root_index = -1; 
        
        for i in range(N): 
            if inorder[i] == preorder[0]: 
                root_index = i 
                break
        
        if root_index == -1: 
            return 0;
        
        # matching element in postorder array
        if preorder[0] != postorder[N-1]:
            return 0;
        
        # check for the left subtree 
        left_tree = self.checktree(preorder[1:], inorder, postorder, root_index); 
        
        # check for the right subtree     
        right_tree = self.checktree(preorder[root_index + 1:], inorder[root_index + 1:], 
                            postorder[root_index:], N-root_index-1); 
        
        # return 1 only if both of them are correct else 0 
        return (left_tree and right_tree)
        # Your code goes here


#{ 
#Driver Code Starts.

# Driver Code 
if __name__ == "__main__": 
    t = int(input())
    for _ in range(t):
        n = int(input())
        preorder = list(map(int, input().strip().split()))
        inorder = list(map(int, input().strip().split()))
        postorder = list(map(int, input().strip().split()))
        obj = Solution()
        if(obj.checktree(preorder, inorder, postorder, n)):
            print("Yes") 
        else: 
            print("No") 


#} Driver Code Ends