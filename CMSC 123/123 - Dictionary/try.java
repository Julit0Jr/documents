if(minimum.rightChild == null) {
  minimum.parent.rightChild = null; 
} 
if(minimum.rightChild != null) {
  minimum.parent.leftChild = minimum.rightChild;
}


if(node.rightChild == minimum) {
  node.rightChild = minimum.rightChild;
} if(minimum.rightChild == null) {
  minimum.parent.rightChild = null;
} if(minimum.rightChild != null) {
  minimum.parent.leftChild = minimum.rightChild;
  minimum.rightChild.parent = minimum.parent;
}
node.entry = minimum.entry;