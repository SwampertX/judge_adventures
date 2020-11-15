struct MyHashSet {
    arr: Vec<bool>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyHashSet {
    /** Initialize your data structure here. */
    fn new() -> Self {
        MyHashSet {
            arr: vec![false; 1000001],
        }
    }

    fn add(&mut self, key: i32) {
        self.arr[key as usize] = true;
    }

    fn remove(&mut self, key: i32) {
        self.arr[key as usize] = false;
    }

    /** Returns true if this set contains the specified element */
    fn contains(&self, key: i32) -> bool {
        self.arr[key as usize]
    }
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * let obj = MyHashSet::new();
 * obj.add(key);
 * obj.remove(key);
 * let ret_3: bool = obj.contains(key);
 */
fn main() {
    let mut obj = MyHashSet::new();
    obj.add(3);
    obj.remove(2);
    let ret_3: bool = obj.contains(3);
    println!("{}", ret_3);
    let ret_2: bool = obj.contains(2);
    println!("{}", ret_2);
}
