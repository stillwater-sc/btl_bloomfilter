/* automatically create main() function to run tests */
#define CATCH_CONFIG_MAIN
/* lightweight unit test framework */
#include "catch.hpp"
#include <vector>

using namespace std;

/* remove #if/#endif when BloomMap is implemented */
#include "BloomMap.hpp"

TEST_CASE("insert and query", "[BloomMap]")
{
	const size_t bloomSize = 1000;
	const unsigned numHashes = 4;
	/* unused in this test */
	const unsigned k = 0;

	BloomMap<int> bloomMap(bloomSize, numHashes, k);

	vector<size_t> hashes;
	vector<int> values;

	hashes.push_back(0);
	hashes.push_back(1);
	hashes.push_back(2);
	hashes.push_back(3);

	values.push_back(0);
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);

	bloomMap.insert(hashes, values);

	vector<int> retrieved = bloomMap.query(hashes);


	REQUIRE((retrieved.size() == 4));
	REQUIRE((retrieved.at(0) == 0));
	REQUIRE((retrieved.at(1) == 1));
	REQUIRE((retrieved.at(2) == 2));
	REQUIRE((retrieved.at(3) == 3));
}
