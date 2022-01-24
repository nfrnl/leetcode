// 284. Peeking Iterator
// https://leetcode.com/problems/peeking-iterator/

package leetcode

type Iterator struct{}

func (this *Iterator) hasNext() bool {
	// Returns true if the iteration has more elements.
	return true
}

func (this *Iterator) next() int {
	// Returns the next element in the iteration.
	return 0
}

type PeekingIterator struct {
	iterator *Iterator
	hasCached bool
	cached int
}

func Constructor(iter *Iterator) *PeekingIterator {
	return &PeekingIterator{iterator: iter}
}

func (this *PeekingIterator) hasNext() bool {
	return this.hasCached || this.iterator.hasNext()
}

func (this *PeekingIterator) next() int {
	if this.hasCached {
		this.hasCached = false
		return this.cached
	}
	return this.iterator.next()
}

func (this *PeekingIterator) peek() int {
	if this.hasCached {
		return this.cached
	}
	this.cached = this.iterator.next()
	this.hasCached = true
	return this.cached
}
