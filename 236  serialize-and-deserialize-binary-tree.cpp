class Codec {
public:
    const string MARKER = "M"; // Marker for null nodes

    // Helper function to serialize the tree
    void serializeRec(TreeNode* root, vector<string>& stream) {
        if (root == nullptr) {
            // Add marker for null nodes
            stream.push_back(MARKER);
            return;
        }

        // Add node value
        stream.push_back(to_string(root->val));

        // Recurse for left and right subtrees
        serializeRec(root->left, stream);
        serializeRec(root->right, stream);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> stream;
        serializeRec(root, stream);

        // Join the stream vector into a single string with commas separating
        // values
        string result;
        for (const string& s : stream) {
            result += s + ",";
        }
        // Remove the last comma
        if (!result.empty())
            result.pop_back();
        return result;
    }

    // Helper function to deserialize the tree
    TreeNode* deserializeRec(queue<string>& nodes) {
        // Get the front node from the queue
        string val = nodes.front();
        nodes.pop();

        // If we encounter the marker, return null
        if (val == MARKER) {
            return nullptr;
        }

        // Create a new TreeNode with the value
        TreeNode* node = new TreeNode(stoi(val));

        // Recurse for left and right subtrees
        node->left = deserializeRec(nodes);
        node->right = deserializeRec(nodes);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string item;

        // Split the string by commas and add each value to the queue
        while (getline(ss, item, ',')) {
            nodes.push(item);
        }

        // Recursively build the tree
        return deserializeRec(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
