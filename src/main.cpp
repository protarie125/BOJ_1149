#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

auto rgb = vvi{};
auto mn = vvi{};

int solvePart(int i, int c) {
	if (-1 == i) {
		return 0;
	}

	if (mn[i][c] < 0) {
		auto c1 = (c + 1) % 3;
		auto c2 = (c + 2) % 3;

		auto a1 = solvePart(i - 1, c1) + rgb[i][c];
		auto a2 = solvePart(i - 1, c2) + rgb[i][c];

		mn[i][c] = a1 < a2 ? a1 : a2;
	}

	return mn[i][c];
}

int solve(int i) {
	if (-1 == i) {
		return 0;
	}

	const auto& c0 = solvePart(i, 0);
	const auto& c1 = solvePart(i, 1);
	const auto& c2 = solvePart(i, 2);

	return min({ c0, c1, c2 });
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; cin >> n;
	rgb = vvi(n, vi(3));
	mn = vvi(n, vi(3, -1));
	for (auto i = 0; i < n; ++i) {
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	cout << solve(n - 1);

	return 0;
}